#ifndef CLOUD_H
#define CLOUD_H

/*
 * Draw an Ellipsoid cloud
 */

#include <random>
#include "drawableobject.h"

enum Shape {
    Ellipsoid,
};

class Cloud : public DrawableObject {
private:
    float a, b, c;
    size_t npoints;

    // Tricky: choose a function for the "into" test
    // Which depends of the desired shape
    typedef bool(Cloud::*Into)(float x, float y, float z);
    Into into_test;

    bool into_Ellipsoid(float x, float y, float z);

public:
    Cloud(float a, float b, float c, size_t npoints, Shape shape);
    ~Cloud() override;
    bool build(QOpenGLShaderProgram* program) override;
};

#endif // CLOUD_H
