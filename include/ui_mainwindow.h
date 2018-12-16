/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "include/meshviewerwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_OBJ;
    QAction *actionExit;
    QAction *actionLaplace_Beltrami;
    QAction *action_phong;
    QAction *action_flat;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *left_layout;
    MeshViewerWidget *viewer;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menu_render;
    QMenu *menu_smooth;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(941, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 500));
        MainWindow->setAnimated(true);
        actionLoad_OBJ = new QAction(MainWindow);
        actionLoad_OBJ->setObjectName(QStringLiteral("actionLoad_OBJ"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLaplace_Beltrami = new QAction(MainWindow);
        actionLaplace_Beltrami->setObjectName(QStringLiteral("actionLaplace_Beltrami"));
        actionLaplace_Beltrami->setEnabled(false);
        action_phong = new QAction(MainWindow);
        action_phong->setObjectName(QStringLiteral("action_phong"));
        action_flat = new QAction(MainWindow);
        action_flat->setObjectName(QStringLiteral("action_flat"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        left_layout = new QVBoxLayout();
        left_layout->setObjectName(QStringLiteral("left_layout"));
        viewer = new MeshViewerWidget(centralWidget);
        viewer->setObjectName(QStringLiteral("viewer"));
        viewer->setFocusPolicy(Qt::StrongFocus);

        left_layout->addWidget(viewer);


        horizontalLayout->addLayout(left_layout);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(200, 16777215));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 91, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 100, 81, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 140, 54, 17));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(3, 294, 201, 271));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 170, 54, 17));

        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 941, 23));
        menu_render = new QMenu(menubar);
        menu_render->setObjectName(QStringLiteral("menu_render"));
        menu_smooth = new QMenu(menu_render);
        menu_smooth->setObjectName(QStringLiteral("menu_smooth"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_render->menuAction());
        menu_render->addAction(menu_smooth->menuAction());
        menu_smooth->addAction(action_phong);
        menu_smooth->addAction(action_flat);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad_OBJ->setText(QApplication::translate("MainWindow", "&Load OBJ", 0));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", 0));
        actionLaplace_Beltrami->setText(QApplication::translate("MainWindow", "&Laplace-Beltrami", 0));
        action_phong->setText(QApplication::translate("MainWindow", "&Phong", 0));
        action_flat->setText(QApplication::translate("MainWindow", "&Flat", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Display options", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Tutorial : </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        menu_render->setTitle(QApplication::translate("MainWindow", "Re&nder", 0));
        menu_smooth->setTitle(QApplication::translate("MainWindow", "&Smooth", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
