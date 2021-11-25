/********************************************************************************
** Form generated from reading UI file 'CScreenShot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSCREENSHOT_H
#define UI_CSCREENSHOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiCScreenShot
{
public:
    QWidget *centralWidget;
    QPushButton *btnScreenShot;
    QLabel *label;
    QPushButton *btnModel;
    QPushButton *btnArrow;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UiCScreenShot)
    {
        if (UiCScreenShot->objectName().isEmpty())
            UiCScreenShot->setObjectName(QStringLiteral("UiCScreenShot"));
        UiCScreenShot->resize(525, 253);
        UiCScreenShot->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(UiCScreenShot);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnScreenShot = new QPushButton(centralWidget);
        btnScreenShot->setObjectName(QStringLiteral("btnScreenShot"));
        btnScreenShot->setGeometry(QRect(20, 10, 71, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        btnScreenShot->setFont(font);
        btnScreenShot->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 180, 521, 2));
        label->setMaximumSize(QSize(530, 2));
        label->setStyleSheet(QStringLiteral("background-color: rgb(81, 81, 81);"));
        btnModel = new QPushButton(centralWidget);
        btnModel->setObjectName(QStringLiteral("btnModel"));
        btnModel->setGeometry(QRect(140, 10, 71, 61));
        btnModel->setFont(font);
        btnModel->setStyleSheet(QStringLiteral(""));
        btnArrow = new QPushButton(centralWidget);
        btnArrow->setObjectName(QStringLiteral("btnArrow"));
        btnArrow->setGeometry(QRect(210, 50, 20, 20));
        UiCScreenShot->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UiCScreenShot);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 525, 23));
        UiCScreenShot->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UiCScreenShot);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        UiCScreenShot->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UiCScreenShot);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UiCScreenShot->setStatusBar(statusBar);

        retranslateUi(UiCScreenShot);

        QMetaObject::connectSlotsByName(UiCScreenShot);
    } // setupUi

    void retranslateUi(QMainWindow *UiCScreenShot)
    {
        UiCScreenShot->setWindowTitle(QApplication::translate("UiCScreenShot", "CScreenShot", Q_NULLPTR));
        btnScreenShot->setText(QString());
        label->setText(QString());
        btnModel->setText(QString());
        btnArrow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UiCScreenShot: public Ui_UiCScreenShot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSCREENSHOT_H
