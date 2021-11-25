/********************************************************************************
** Form generated from reading UI file 'CCanvas.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCANVAS_H
#define UI_CCANVAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiCCanvas
{
public:
    QWidget *centralwidget;
    QPushButton *btnScreenShot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UiCCanvas)
    {
        if (UiCCanvas->objectName().isEmpty())
            UiCCanvas->setObjectName(QStringLiteral("UiCCanvas"));
        UiCCanvas->resize(800, 600);
        centralwidget = new QWidget(UiCCanvas);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btnScreenShot = new QPushButton(centralwidget);
        btnScreenShot->setObjectName(QStringLiteral("btnScreenShot"));
        btnScreenShot->setGeometry(QRect(30, 30, 71, 41));
        btnScreenShot->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../ScreenShotGitHub/Screenshot-with-picture-edit-Based-on-Qt/image/control_09.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btnScreenShot->setIcon(icon);
        btnScreenShot->setIconSize(QSize(42, 46));
        UiCCanvas->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UiCCanvas);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        UiCCanvas->setMenuBar(menubar);
        statusbar = new QStatusBar(UiCCanvas);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UiCCanvas->setStatusBar(statusbar);

        retranslateUi(UiCCanvas);

        QMetaObject::connectSlotsByName(UiCCanvas);
    } // setupUi

    void retranslateUi(QMainWindow *UiCCanvas)
    {
        UiCCanvas->setWindowTitle(QApplication::translate("UiCCanvas", "MainWindow", Q_NULLPTR));
        btnScreenShot->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UiCCanvas: public Ui_UiCCanvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCANVAS_H
