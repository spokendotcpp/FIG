#ifndef CLOUD_H
#define CLOUD_H

#include <random>
#include <deque>
#include "drawableobject.h"

class Cloud : public DrawableObject {
protected:
    float Ox, Oy, Oz;
    size_t total_points;
    float dmin;
    std::deque<float> into_points;

public:
    Cloud(float Ox, float Oy, float Oz, size_t pts, float dmin=0.001f);
    ~Cloud() override;
    bool build(QOpenGLShaderProgram* program) override;

    /* Returns the gravity center */
    QVector3D compute_gravity_center() const;

    /* virtual function, can be redifined into child class */
    virtual
    bool into(float x, float y, float z);

    /* Static functions */
    static
    float distance(float x, float y, float z, float xx, float yy, float zz);
};

class EllipsoidCloud : public Cloud
{
public:
    EllipsoidCloud(float Ox, float Oy, float Oz, size_t pts, float dmin=0.001f);
    bool into(float x, float y, float z) override;
};

#endif // CLOUD_H
