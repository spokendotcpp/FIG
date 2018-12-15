#ifndef CLOUD_CPP
#define CLOUD_CPP

#include <iostream>
#include "../include/cloud.h"

Cloud::Cloud(float _a, float _b, float _c, size_t pts):
    a(_a), b(_b), c(_c), npoints(pts)
{
    if( a < 0.0f ) a = 1.0f;
    if( b < 0.0f ) b = 1.0f;
    if( c < 0.0f ) c = 1.0f;
}

Cloud::~Cloud()
{}

bool
Cloud::build(QOpenGLShaderProgram* program)
{
    GLfloat* positions = new GLfloat[npoints * 3];
    GLuint* indices = new GLuint[npoints];

    // BUILD CLOUD
    std::random_device rd;
    std::default_random_engine re(rd());

    std::uniform_real_distribution<float> Ox{-a, a};
    std::uniform_real_distribution<float> Oy{-b, b};
    std::uniform_real_distribution<float> Oz{-c, c};

    for(size_t i=0; i < npoints; ++i){

        bool on_ellipsoid = false;
        while( !on_ellipsoid ){
            float x = Ox(re);
            float y = Oy(re);
            float z = Oz(re);

            // Maths from https://en.wikipedia.org/wiki/Ellipsoid
            if( (((x*x)/(a*a)) + ((y*y)/(b*b)) + ((z*z)/(c*c))) <= 1.0f ){
                positions[(i*3)+0] = x;
                positions[(i*3)+1] = y;
                positions[(i*3)+2] = z;
                on_ellipsoid = true;
            }
        }

        indices[i] = GLuint(i);
    }

    // BUILD BUFFERS (will be sent to GPU with `update_buffers()` method.
    set_vertices_geometry(
        program->attributeLocation("position"), positions, indices);

    set_vertices_colors(
        program->attributeLocation("color"), new GLfloat[npoints*3]);

    return initialize(npoints, npoints, 3);
}

#endif // CLOUD_CPP