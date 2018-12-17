#ifndef CLOUD_H
#define CLOUD_H

#include <random>
#include <deque>
#include "drawableobject.h"
#include "axis.h"

#include <Eigen/Eigenvalues>
#include <Eigen/Dense>

using Eigen::MatrixXf;
using Eigen::EigenSolver;

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
    MatrixXf compute_correlation_matrix() const;

    /* Draw eigen vectors */
    Axis* compute_axis() const;

    /* Virtual function, can be redifined into child class */
    virtual
    bool into(float x, float y, float z);

    /* Static functions */
    /* Euclidean distance between two 3D points */
    static
    float distance(float x, float y, float z, float xx, float yy, float zz);

    /* Determinant of a 3x3 matrix */
    static
    float compute_determinant(const std::deque<float>& mat3x3);

    /* Egeins values of a 3x3 matrix */
    static
    std::deque<float> eigenvalues(const std::deque<float>& mat3x3);

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
