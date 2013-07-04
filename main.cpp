#include "guip0f.h"
#include <QApplication>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include "QtNetwork/qnetworkinterface.h"
#include "QtNetwork/QNetworkInterface"
#include "QList"
#include "qlist.h"

extern "C"{
#include "p0f.h"
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUIp0f w;

    printf("%d\n",setuid(0));

    printf("%d",getuid());
    char stringa[10]="wlan0";
    u8* iface=(u8*)stringa;

    set_up_iface(iface);
   // list_interfaces();
    w.show();
    
    return a.exec();
}
