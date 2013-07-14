#include "guip0f.h"
#include "ui_guip0f.h"
#include <QDebug>
#include <QNetworkInterface>
#include "p0f_auditor.h"
#include "network_db.h"
extern "C" {
#include "p0f.h"
}


GUIp0f::GUIp0f(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUIp0f)
{

    ui->setupUi(this);
    create_list_interface();
    timer_update = new QTimer(this);
    connect(timer_update,SIGNAL(timeout()),this,SLOT(update_gui()));
    if(!timer_update->isActive()){
        timer_update->start(10000);
    }

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

void GUIp0f::stop_p0f(){
    my.terminate();
    timer_update->stop();
}

void GUIp0f::update_gui(){
    qDebug()<<"timer running timeout";
    network_db data = network_db::get_istance();
    qDebug()<<data.network.size();
    for (int i=0;i<data.network.size();i++){
        qDebug()<<"<--------------------------------------------------------------------------->";
        qDebug()<<"host n "<<i<<" ip "<<data.network[i]->get_ip();
        data.network[i]->print_packets();



    }




}



GUIp0f::~GUIp0f()
{
    delete ui;
}
