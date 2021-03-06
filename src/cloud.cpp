#ifndef CLOUD_CPP
#define CLOUD_CPP

#include <iostream>
#include "../include/cloud.h"
#include <Eigen/Dense>

using Eigen::MatrixXd;

Cloud::Cloud(float _Ox, float _Oy, float _Oz, size_t _total_points, float _dmin):
    Ox(_Ox), Oy(_Oy), Oz(_Oz), total_points(_total_points), dmin(_dmin)
{
    if( dmin < 0.0f ) dmin = 0.001f;
    if( Ox < 0.0f )   Ox   = 1.0f;
    if( Oy < 0.0f )   Oy   = 1.0f;
    if( Oz < 0.0f )   Oz   = 1.0f;
}

Cloud::~Cloud()
{
    into_points.clear();
}

bool
Cloud::build(QOpenGLShaderProgram* program)
{
    // BUILD CLOUD
    std::random_device rd;
    std::default_random_engine re(rd());

    // Generators
    std::uniform_real_distribution<float> xgen{-Ox, Ox};
    std::uniform_real_distribution<float> ygen{-Oy, Oy};
    std::uniform_real_distribution<float> zgen{-Oz, Oz};

    // Prepare deque to receive information
    into_points.clear();

    for(size_t i=0; i < total_points; ++i){
        float x = xgen(re);
        float y = ygen(re);
        float z = zgen(re);

        if( into(x, y, z) ){
            bool distance_ok = true;
            for(size_t j=0; j < into_points.size(); j+=3){
                float dist = distance(
                    x, y, z,
                    into_points[j+0],
                    into_points[j+1],
                    into_points[j+2]
                );

                if( dist <= dmin ){
                    distance_ok = false;
                    break;
                }
            }

            if( distance_ok ){
                into_points.push_back(x);
                into_points.push_back(y);
                into_points.push_back(z);
            }
        }
    }

    // Once we have all the correct points into our shape.
    // Build datas
    size_t npoints = into_points.size()/3;
    GLfloat* positions = new GLfloat[npoints*3];
    GLuint* indices = new GLuint[npoints];

    for(size_t i=0; i < npoints; ++i){
        size_t idx = (i*3);
        positions[idx+0] = into_points[idx+0];
        positions[idx+1] = into_points[idx+1];
        positions[idx+2] = into_points[idx+2];
        indices[i] = GLuint(i);
    }

    // BUILD BUFFERS (will be sent to GPU with `update_buffers()` method.
    set_vertices_geometry(
        program->attributeLocation("position"), positions, indices);

    set_vertices_colors(
        program->attributeLocation("color"), new GLfloat[npoints*3]);

    return initialize(npoints, npoints, 3);
}


QVector3D
Cloud::compute_gravity_center() const
{
    QVector3D gcenter(0.0f, 0.0f, 0.0f);
    size_t npoints = into_points.size()/3;

    for(size_t i=0; i < npoints; ++i){
        size_t idx = (i*3);
        gcenter += QVector3D(
            into_points[idx+0],
            into_points[idx+1],
            into_points[idx+2]
        );
    }

    return model_matrix() * (gcenter/float(npoints));
}

std::deque<float>
Cloud::compute_deviations() const
{
    std::deque<float> deviations(into_points.size());
    QVector3D gcenter = compute_gravity_center();
    size_t npoints = points_into_cloud();

    std::cerr << gcenter[0] << " " << gcenter[1] << " " << gcenter[2] << std::endl;

    for(size_t i=0; i < npoints; ++i){
        size_t idx = (i*3);

        QVector3D p(
            into_points[idx+0],
            into_points[idx+1],
            into_points[idx+2]
        );

        p = model_matrix() * p;

        deviations[idx+0] = p[0] - gcenter.x();
        deviations[idx+1] = p[1] - gcenter.y();
        deviations[idx+2] = p[2] - gcenter.z();
    }

    return deviations;
}

std::deque<float>
Cloud::compute_correlation_matrix() const
{
    std::deque<float> deviations = compute_deviations();
    size_t npoints = points_into_cloud();

    //          | x0, y0, z0 |
    // matrix   | x1, y1, z1 |
    //          | x2, y2, z2 |
    //
    //          | x0, x1, x2 |
    // t_matrix | y0, y1, y2 |
    //          | z0, z1, z2 |
    std::deque<std::deque<float>> matrix(npoints);

    std::deque<std::deque<float>> t_matrix(3);
    t_matrix[0] = std::deque<float>(npoints); // x
    t_matrix[1] = std::deque<float>(npoints); // y
    t_matrix[2] = std::deque<float>(npoints); // z

    for(size_t i=0; i < npoints; ++i){
        size_t idx = (i*3);
        matrix[i] = std::deque<float>(3);
        matrix[i][0] = t_matrix[0][i] = deviations[idx+0];
        matrix[i][1] = t_matrix[1][i] = deviations[idx+1];
        matrix[i][2] = t_matrix[2][i] = deviations[idx+2];
    }

    std::cerr << matrix.size() << " " << t_matrix[0].size() << std::endl;

    // Correlation matrix (out)[3*3] = t_matrix[3*npts] * matrix[npts*3];
    std::deque<float> out(9);
    for(size_t i=0; i < 3; ++i){
        for(size_t j=0; j < 3; ++j){
            out[(i*3)+j] = 0.0f;
            for(size_t h=0; h < npoints; ++h){
                out[(i*3)+j] += (t_matrix[i][h] * matrix[h][j]);
            }
        }
    }

    return out;
}

// Compute determinant of a matrix (3x3)
float
Cloud::compute_determinant(const std::deque<float>& mat)
{
    if(mat.size() != 9)
        return 0;

    return + mat[0]*((mat[4]*mat[8]) - (mat[5]*mat[7]))
           - mat[1]*((mat[3]*mat[8]) - (mat[5]*mat[6]))
           + mat[2]*((mat[3]*mat[7]) - (mat[4]*mat[6]));
}

//https://en.wikipedia.org/wiki/Eigenvalue_algorithm#3%C3%973_matrices
std::deque<float>
Cloud::eigenvalues(const std::deque<float>& matrix)
{
    std::deque<float> eigenvalues(3);
    if( matrix.size() == 9 ){
        float r0 = (matrix[1]*matrix[1]) +
                   (matrix[2]*matrix[2]) +
                   (matrix[5]*matrix[5]);

        if( r0 == 0.0f ){
            eigenvalues[0] = matrix[0];
            eigenvalues[1] = matrix[4];
            eigenvalues[2] = matrix[8];
        }
        else {
            float q = (matrix[0] + matrix[4] + matrix[8])/3;
            float r1 = (
                std::pow(matrix[0] - q, 2.0f) +
                std::pow(matrix[4] - q, 2.0f) +
                std::pow(matrix[8] - q, 2.0f) +
                2 * r0
            );

            float p = std::sqrt(r1/6);
            std::deque<float> A_minus_LambdaI = matrix;
            A_minus_LambdaI[0] -= q;
            A_minus_LambdaI[4] -= q;
            A_minus_LambdaI[8] -= q;

            for(size_t i = 0; i < 9; ++i)
                A_minus_LambdaI[i] *= (1/p);

            float det = Cloud::compute_determinant(A_minus_LambdaI)/2.0f;
            float phi;
            const float PI = std::atan(1.0f) * 4.0f;

            if( det <= -1 ){
                phi = PI / 3.0f;
            }
            else
            if( det >= 1 ){
                phi = 0.0f;
            }
            else {
                phi = std::acos(det) / 3.0f;
            }

            eigenvalues[0] = q + 2 * p * std::cos(phi);
            eigenvalues[2] = q + 2 * p * std::cos(phi + (2*PI/3));
            eigenvalues[1] = 3 * q - eigenvalues[0] - eigenvalues[2];
        }
    }

    return eigenvalues;
}

// Naive test
bool
Cloud::into(float x, float y, float z)
{
    return (  (x >= -Ox && x <= Ox)
           && (y >= -Oy && y <= Oy)
           && (z >= -Oz && z <= Oz) );
}

// Compute euclidean distance between two 3D points.
float
Cloud::distance(float x, float y, float z, float xx, float yy, float zz)
{
    return std::sqrt(
                std::pow(xx-x, 2.0f) +
                std::pow(yy-y, 2.0f) +
                std::pow(zz-z, 2.0f));
}

// ELLIPSOID CLOUD CLASS
EllipsoidCloud::EllipsoidCloud(float _Ox, float _Oy, float _Oz, size_t _total_points, float _dmin):
    Cloud(_Ox, _Oy, _Oz, _total_points, _dmin)
{}

// Maths from https://en.wikipedia.org/wiki/Ellipsoid
bool
EllipsoidCloud::into(float x, float y, float z)
{
    return (((x*x)/(Ox*Ox)) + ((y*y)/(Oy*Oy)) + ((z*z)/(Oz*Oz))) <= 1.0f;
}

#endif // CLOUD_CPP
