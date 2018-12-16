#ifndef CLOUD_CPP
#define CLOUD_CPP

#include <iostream>
#include "../include/cloud.h"

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
        gcenter.setX(gcenter.x() + into_points[idx+0]);
        gcenter.setY(gcenter.y() + into_points[idx+1]);
        gcenter.setZ(gcenter.z() + into_points[idx+2]);
    }

    return gcenter/npoints;
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
    return std::sqrt(std::pow(xx-x, 2.0f) + std::pow(yy-y, 2.0f) + std::pow(zz-z, 2.0f));
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
