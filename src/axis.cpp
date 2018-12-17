#include "../include/axis.h"
#include <iostream>

Axis::Axis(QVector3D _origin, QVector3D _dir0, QVector3D _dir1, QVector3D _dir2)
    :origin(_origin), dir0(_dir0), dir1(_dir1), dir2(_dir2)
{}

bool
Axis::build(QOpenGLShaderProgram* program)
{
    size_t nb_vertices = 6;

    GLfloat* positions = new GLfloat[nb_vertices*3] {
        origin.x(), origin.y(), origin.z(),
        dir0.x(), dir0.y(), dir0.z(),
        origin.x(), origin.y(), origin.z(),
        dir1.x(), dir1.y(), dir1.z(),
        origin.x(), origin.y(), origin.z(),
        dir2.x(), dir2.y(), dir2.z()
    };

    GLfloat* colors = new GLfloat[nb_vertices*3] {
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };

    GLuint* indices = new GLuint[nb_vertices] {
        0, 1,  2, 3,  4, 5
    };

    set_vertices_geometry(program->attributeLocation("position"), positions, indices);
    set_vertices_colors(program->attributeLocation("color"), colors);

    return initialize(nb_vertices, nb_vertices, 3);
}
