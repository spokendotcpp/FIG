#include "../include/mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent), ui(new Ui::MainWindow())
{
    ui->setupUi(this);
    ui->viewer->set_frames_per_second(60);

    this->setWindowTitle("Clouds");
    this->resize(1280, 720);
    this->center();

    ui->spinbox_ox->setValue(1.0);
    ui->spinbox_oy->setValue(1.0);
    ui->spinbox_oz->setValue(1.0);
    ui->spinbox_nb_pts->setValue(500);
    ui->spinbox_dmin->setValue(0.001);

    connect_signals_and_slots();

    // start a Callback timer of (1s, 1000ms)
    startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void
MainWindow::center()
{
    QSize ssize = QApplication::primaryScreen()->size();
    int w = size().width();
    int h = size().height();

    this->setGeometry(
        (ssize.width() - w)/2,
        (ssize.height() - h)/2,
        w, h
    );
}

void
MainWindow::keyPressEvent(QKeyEvent* event)
{
    if( event->key() == Qt::Key_Escape )
        close();
    else
        ui->viewer->handle_key_events(event);
}

void
MainWindow::timerEvent(QTimerEvent*)
{
    ui->lcd_fps->display(int(ui->viewer->get_computed_frames()));
    ui->viewer->reset_computed_frames();
}

void
MainWindow::connect_signals_and_slots()
{
    // QUIT APP
    connect(ui->actionQuit, &QAction::triggered, this, &QMainWindow::close);
    connect(ui->button_build, &QPushButton::toggled, this, &MainWindow::on_button_build_pressed);
    connect(ui->action_reset_view, &QAction::triggered, this->ui->viewer, &MeshViewerWidget::reset_view);
}

void MainWindow::on_button_build_pressed()
{
    Cloud* cloud = new EllipsoidCloud(
        float(ui->spinbox_ox->value()),
        float(ui->spinbox_oy->value()),
        float(ui->spinbox_oz->value()),
        size_t(ui->spinbox_nb_pts->value()),
        float(ui->spinbox_dmin->value())
    );

    // Rotation
    cloud->rotate(float(ui->spinbox_rotation_x->value()), 1.0f, 0.0f, 0.0f);
    cloud->rotate(float(ui->spinbox_rotation_y->value()), 0.0f, 1.0f, 0.0f);
    cloud->rotate(float(ui->spinbox_rotation_z->value()), 0.0f, 0.0f, 1.0f);

    // Translation
    cloud->translate(
        float(ui->spinbox_center_x->value()),
        float(ui->spinbox_center_y->value()),
        float(ui->spinbox_center_z->value())
    );

    ui->viewer->set_cloud(cloud);
    ui->spinbox_drawn_pts->setValue(int(cloud->points_into_cloud()));
}
