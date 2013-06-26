#include "guip0f.h"
#include <QApplication>
extern "C"{
#include "p0f.h"
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIp0f w;
    list_interfaces();
    w.show();
    
    return a.exec();
}
