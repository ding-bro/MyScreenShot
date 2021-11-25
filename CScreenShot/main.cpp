#include "CScreenShot.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CScreenShot w;
    w.show();
    return a.exec();
}
