#ifndef MESHVIEWERWIDGET_H
#define MESHVIEWERWIDGET_H

#include <chrono>

#include <QApplication>
#include <QScreen>
#include <QSize>

#include <QTimerEvent>

#include <QMouseEvent>
#include <QWheelEvent>

#include <QOpenGLWidget>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>

#include <QMatrix4x4>
#include <QInputDialog>

#include "axis.h"
#include "light.h"
#include "arcball.h"
#include "cloud.h"

#include <iostream>

typedef std::chrono::steady_clock Clock;

/*
 * QGLWidget child class.
 */

class MeshViewerWidget: public QOpenGLWidget
{
    Q_OBJECT
/* Private members */
private:
    /* GLSL Shaders */
    QOpenGLShaderProgram* program;

    /* Matrix which compose our Model View Projection Matrix -- uniform values */
    QMatrix4x4 view;
    QMatrix4x4 projection;

    // FPS related
    Clock::time_point lap;
    long frequency;
    size_t frames;
    int timer_id_0;

    // Mouse related
    bool mouse_pressed;
    bool wheel_pressed;
    QPoint mouse;
    QVector3D position;
    QMatrix4x4 rotation;

    // Viewport related
    float fov;
    float zNear;
    float zFar;
    float window_ratio;

    // User objects into our scene
    Light* light;
    ArcBall* arcball;
    Axis* axis;
    Cloud* cloud;

    // DISPLAY METHODS
    bool wireframe_on;
    bool fill_on;
    bool smooth_on;

/* Public methods */
public:
    MeshViewerWidget(QWidget *parent=nullptr);
    ~MeshViewerWidget() override;

    /* *********************************************** */
    /* Qt OpenGL override functions */
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

    /* Qt override functions */
    /* Mouse */
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

    /* QTimerEvent */
    void timerEvent(QTimerEvent*) override;

    /* Wheel */
    void wheelEvent(QWheelEvent*) override;

    /* *********************************************** */
    /* User defined methods */
    /* Since we don't want our QMainWindow to lose Focus,
     * we handle key events with our own function.
     * See mainwindow.cpp > keyPressEvent method.
     */
    void handle_key_events(QKeyEvent*);

    /* caps frames per second */
    void set_frames_per_second(size_t fps);

    /* Number of frames drawn during the last second */
    size_t get_computed_frames() const;

    /* Reset counter */
    void reset_computed_frames();

    /* Flat or Smooth render */
    void smooth_render(bool on);

    /* Display using GL_LINES PolygonMode */
    void display_wireframe(bool mode);

    /* Display using GL_FILL PolygonMode */
    void display_fill(bool mode);

    /* Reset view matrix to default */
    void reset_view();


    /* INLINE FUNCTIONS */
    inline
    const Cloud* get_cloud() const
    {
        return cloud;
    }

    inline
    void set_cloud(Cloud* c)
    {
        if( cloud != nullptr )
            delete cloud;

        cloud = c;

        makeCurrent();
        program->bind();

        cloud->build(program);
        cloud->use_unique_color(1.0f, 1.0f, 0.0f);
        cloud->update_buffers(program);

        std::cerr << " ________________________ " << std::endl;
        std::deque<float> inertia = cloud->compute_correlation_matrix();
        for(size_t i=0; i < inertia.size(); ++i){
            std::cerr << inertia[i] << ", ";
            if( (i+1)%3 == 0 )
                std::cerr << std::endl;
        }

        program->release();
        doneCurrent();
        update();
    }
    /* ________________ */


    /* *********************************************** */
    /* STATIC METHODS */
    /* Difference between two high resolution clock time point as microseconds */
    static
    long microseconds_diff(Clock::time_point t1, Clock::time_point t2);

/* Private methods */
private:
    void default_view();
    void default_projection();
    void default_ModelViewPosition();

    void update_view();
    void update_projection();

    void update_lap();
};

#endif // MESHVIEWERWIDGET_H
