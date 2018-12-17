#ifndef AXIS_H
#define AXIS_H

#include "drawableobject.h"

class Axis : public DrawableObject
{
private:
    QVector3D origin;
    QVector3D dir0;
    QVector3D dir1;
    QVector3D dir2;

public:
    Axis(QVector3D origin =QVector3D(0.0f, 0.0f, 0.0f),
         QVector3D dir0 =QVector3D(1.0f, 0.0f, 0.0f),
         QVector3D dir1 =QVector3D(0.0f, 1.0f, 0.0f),
         QVector3D dir2 =QVector3D(0.0f, 0.0f, 1.0f));

    bool build(QOpenGLShaderProgram* program) override;
};

#endif // AXIS_H
