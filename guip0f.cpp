#include "guip0f.h"
#include "ui_guip0f.h"
#include <QDebug>
#include <QNetworkInterface>
#include "p0f_auditor.h"
#include "network_db.h"
#include <QLayout>
#include <QGroupBox>
#include <QMessageBox>
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

    ui->groupBox->setLayout(ui->gridLayout);


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
    print_network();
    network_db* data = network_db::get_istance();
    data->show_network();
    set_list_ip();
    qDebug()<<data->get_hosts().size()<<" in gui";
}

void GUIp0f::update_gui(){
    qDebug()<<"timer running timeout";
    print_network();
    network_db* data = network_db::get_istance();
    data->show_network();
    set_list_ip();

/*
    QString prova = "ciao";
    QLabel* ciao = new QLabel(prova,ui->frame);
    ciao->setVisible(true);
    QLabel* ciao1 = new QLabel(prova,ui->frame);
    ciao1->setVisible(true);
    QLabel* ciao2 = new QLabel(prova,ui->frame);
    ciao2->setVisible(true);
    QLabel* ciao3 = new QLabel(prova,ui->frame);
    ciao3->setVisible(true);
    ui->gridLayout->addWidget(ciao,0,0);
    ui->gridLayout->addWidget(ciao1,1,1);
    ui->gridLayout->addWidget(ciao2,2,2);
    ui->gridLayout->addWidget(ciao3,3,3);

*/

}

void GUIp0f::set_list_ip(){
    network_db* data = network_db::get_istance();
    if(data->get_hosts().size()>0){
        //clear list host
        ui->listWidget->clear();
        QLayoutItem* eliminate;
        while((eliminate = ui->gridLayout->takeAt(0))!=0){
            delete eliminate->widget();
        }

        //add image host
        for(int i=0,row=0,column=0;i<data->get_hosts().size();i++,column++){
            ui->listWidget->addItem(data->get_hosts()[i]->get_ip());
            QLabel* prova = new QLabel(data->get_hosts()[i]->get_ip(),ui->groupBox);
            if(column==5){
                row++;
                column=0;
            }
            ui->gridLayout->addWidget(prova,row,column);
        }
    }

}

void GUIp0f::see_info_host(){
    network_db* data = network_db::get_istance();
    QString host = ui->listWidget->currentItem()->text();
    for(int i=0;i<data->get_hosts().size();i++){
        if(data->get_hosts()[i]->get_ip().compare(host)==0){
            QString info = "IP host = "+data->get_hosts()[i]->get_ip()+
                    "\n ";
            QMessageBox::information(NULL,"Host Information",info+"\n"+data->get_hosts()[i]->print_packets());
        }
    }

}



GUIp0f::~GUIp0f()
{
    delete ui;
}
