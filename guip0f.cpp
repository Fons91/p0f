#include "guip0f.h"
#include "ui_guip0f.h"
#include <QDebug>
#include <QNetworkInterface>
extern "C" {
#include "p0f.h"
}


GUIp0f::GUIp0f(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUIp0f)
{

    ui->setupUi(this);
    create_list_interface();
}

void GUIp0f::set_name_interface(){

   qDebug()<< QString(ui->list_interface->currentText());
   QString name_interface =QString(ui->list_interface->currentText());
   QByteArray ba = name_interface.toLatin1();
   char *char_interface = ba.data();
   set_up_iface(char_interface);
   //go();
   my.start();
   qDebug()<< "end set name interface";
  // exit(0);
}

void GUIp0f::create_list_interface(){
    QNetworkInterface* network = new QNetworkInterface();
    foreach(QNetworkInterface interface,network->allInterfaces())
        ui->list_interface->addItem(interface.humanReadableName());
}


GUIp0f::~GUIp0f()
{
    delete ui;
}
