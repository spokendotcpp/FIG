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

    /* Returns the into_points minus cloud gravity center */
    std::deque<float> compute_deviations() const;

    /* Correlation matrix tB * B = C */
    std::deque<float> compute_correlation_matrix() const;

    float compute_determinant(const std::deque<float>&) const;

    /* Virtual function, can be redifined into child class */
    virtual
    bool into(float x, float y, float z);

    /* Static functions */
    static
    float distance(float x, float y, float z, float xx, float yy, float zz);

    /* Inline functions */
    inline
    size_t points_into_cloud() const { return into_points.size()/3; }
};

class EllipsoidCloud : public Cloud
{
public:
    EllipsoidCloud(float Ox, float Oy, float Oz, size_t pts, float dmin=0.001f);
    bool into(float x, float y, float z) override;

};

#endif // CLOUD_H
