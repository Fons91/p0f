#include "guip0f.h"
#include <QApplication>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

extern "C"{
#include "p0f.h"
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIp0f w;

    printf("%d\n",setuid(0));

    printf("%d",getuid());

   list_interfaces();
    w.show();
    
    return a.exec();
}
