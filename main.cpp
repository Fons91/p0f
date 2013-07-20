#include "guip0f.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIp0f w;
    w.show();
    return a.exec();
}

