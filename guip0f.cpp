#include "guip0f.h"
#include "ui_guip0f.h"
#include <QDebug>
#include <QNetworkInterface>
#include "p0f_auditor.h"
#include "network_db.h"
#include <QLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QPixmap>
#include <QScrollArea>
#include <QHostInfo>
#include <QTimeLine>
#include "host.h"
extern "C" {
#include "p0f.h"
}


GUIp0f::GUIp0f(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUIp0f)
{

    ui->setupUi(this);
    create_list_interface();
    ui->widget =new QWidget();
    ui->widget->setLayout(ui->gridLayout);
    ui->scrollArea->setWidget(ui->widget);

}

void GUIp0f::set_name_interface(){

   qDebug()<< QString(ui->list_interface->currentText());
   QString name_interface =QString(ui->list_interface->currentText());
   QByteArray ba = name_interface.toLatin1();
   char *char_interface = ba.data();
   set_up_iface(char_interface);
   timer_update = new QTimer(this);
   connect(timer_update,SIGNAL(timeout()),this,SLOT(update_gui()));
   if(!timer_update->isActive()){
       timer_update->start(10000);
   }
   ui->progressBar->setRange(0,100);
   QTimeLine* line = new QTimeLine(10000,this);
   line->setFrameRange(0,100);
   connect(line,SIGNAL(frameChanged(int)),ui->progressBar,SLOT(setValue(int)));
   line->start();
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
    ui->progressBar->setVisible(false);
    qDebug()<<"timer running timeout";
    print_network();
    network_db* data = network_db::get_istance();
    data->show_network();
    set_list_ip();

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

            QLabel *host_image=get_image_host(data->get_hosts()[i]);
            host_image->setFixedHeight(100);
            host_image->setFixedWidth(100);
            QString host_ip = data->get_hosts()[i]->get_ip();
            QLabel *host_name=new QLabel(host_ip);
            host_name->setFixedHeight(20);
            host_name->setFixedWidth(130);
            QFont font( "Arial", 12, QFont::Bold);
            host_name->setFont(font);

            QGroupBox *my_group=new QGroupBox(ui->widget);
            QVBoxLayout *vbox = new QVBoxLayout;
            vbox->addWidget(host_image);
            vbox->addWidget(host_name);
            my_group->setLayout(vbox);
            my_group->show();
            my_group->setFixedHeight(130);
            my_group->setFixedWidth(130);
            if(column==5){
                row++;
                column=0;
            }
            ui->gridLayout->addWidget(my_group,row,column);
        }
    }

}

QLabel* GUIp0f::get_image_host(host  *myhost){
    QLabel* image = new QLabel(ui->widget);
    QString os = myhost->get_syn_packet()->get_os();

    if(os.indexOf("Linux")!=-1){
        image->setStyleSheet("border-image:url(linux.jpg);");
    }else if(os.indexOf("Windows")!=-1){
         image->setStyleSheet("border-image:url(windows.png);");
    }else if(os.indexOf("Mac")!=-1) {
        image->setStyleSheet("border-image:url(mac.jpg);");
    }else if(os.indexOf("FreeBSD")!=-1) {
        image->setStyleSheet("border-image:url(dont_know.jpg);");
    }else if(os.indexOf("OpenBSD")!=-1) {
        image->setStyleSheet("border-image:url(dont_know.jpg);");
    }else if(os.indexOf("Solaris")!=-1) {
        image->setStyleSheet("border-image:url(dont_know.jpg);");
    }else{
        image->setStyleSheet("border-image:url(dont_know.jpg);");
    }

    return image;
}

void GUIp0f::see_info_host(){
    network_db* data = network_db::get_istance();
    QListWidgetItem* current_host = ui->listWidget->currentItem();
    qDebug()<<"print info ip";
    if(current_host!=NULL)
    {
        QString host = current_host->text();
        for(int i=0;i<data->get_hosts().size();i++){
            if(data->get_hosts()[i]->get_ip().compare(host)==0){
                QHostInfo *info_host =new QHostInfo(QHostInfo::fromName(data->get_hosts()[i]->get_ip()));
                 QString info = "IP HOST = "+data->get_hosts()[i]->get_ip()+
                        "\nDOMAIN NAME ="+info_host->hostName()+"\n";
                QMessageBox::information(NULL,"Host Information",info+"\n"+data->get_hosts()[i]->print_packets());
            }
        }
    }

}



GUIp0f::~GUIp0f()
{
    delete ui;
}
