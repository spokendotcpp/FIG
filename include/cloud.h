#ifndef CLOUD_H
#define CLOUD_H

/*
 * Draw an Ellipsoid cloud
 */

#include <random>
#include "drawableobject.h"

class Cloud : public DrawableObject {



public:

    float a, b, c;
    size_t npoints;

    Cloud(float a, float b, float c, size_t npoints);
    ~Cloud() override;
    bool build(QOpenGLShaderProgram* program) override;

};

#endif // CLOUD_H
