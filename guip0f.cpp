#include "guip0f.h"
#include "ui_guip0f.h"
#include <QDebug>
#include <QNetworkInterface>
#include "p0f_auditor.h"
#include "network_db.h"
#include <QLayout>
#include <QGroupBox>
#include <QMessageBox>
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
    searched=false;
    ui->setupUi(this);
    create_list_interface();
    ui->widget =new QWidget();
    ui->widget->setLayout(ui->gridLayout);
    ui->scrollArea->setWidget(ui->widget);
    connect(this,SIGNAL(clicked(QString)),this,SLOT(see_info_host(QString)));

}

void GUIp0f::set_name_interface(){

   qDebug()<< QString(ui->list_interface->currentText());
   QString  name_interface  =QString(ui->list_interface->currentText());
   ui->list_interface->setEnabled(false);
   QByteArray ba = name_interface.toLatin1();
   char *char_interface = ba.data();

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
   set_up_iface(char_interface);
   my.start();

}

void GUIp0f::create_list_interface(){
    QNetworkInterface* network = new QNetworkInterface();
    foreach(QNetworkInterface interface,network->allInterfaces())
        ui->list_interface->addItem(interface.humanReadableName());
}

void GUIp0f::stop_p0f(){
    my.killTimer(0);
    timer_update->stop();
    network_db* data = network_db::get_istance();
    data->show_network();
    set_list_ip();
    qDebug()<<data->get_hosts().size()<<" in gui";
}

void GUIp0f::update_gui(){
    ui->progressBar->setVisible(false);
    qDebug()<<"timer running timeout";
    network_db* data = network_db::get_istance();
    data->show_network();
    if (searched==true){
        search_host();
    }
    else{
        set_list_ip();
    }

}

void GUIp0f::set_list_ip(){
    network_db* data = network_db::get_istance();
    if(data->get_hosts().size()>0){
        //clear list host
        delete_item();
        signal_buttons = new QSignalMapper(this);
        for(int i=0,row=0,column=0;i<data->get_hosts().size();i++){
            add_item_net(data->get_hosts()[i],row,column);
            if(column==4){
                row++;
                column=0;
            }else{
                column++;
            }
        }
        connect(signal_buttons, SIGNAL(mapped(const QString &)),
                     this, SIGNAL(clicked(const QString &)));
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
        image->setStyleSheet("border-image:url(freebsd.jpg);");
    }else if(os.indexOf("OpenBSD")!=-1) {
        image->setStyleSheet("border-image:url(openbsd.jpg);");
    }else if(os.indexOf("Solaris")!=-1) {
        image->setStyleSheet("border-image:url(dont_know.jpg);");
    }else{
        image->setStyleSheet("border-image:url(dont_know.jpg);");
    }

    return image;
}

void GUIp0f::see_info_host(QString host_ip){
    network_db* data = network_db::get_istance();
    for(int i=0;i<data->get_hosts().size();i++){
        if(data->get_hosts()[i]->get_ip().compare(host_ip)==0){
              QHostInfo *info_host =new QHostInfo(QHostInfo::fromName(data->get_hosts()[i]->get_ip()));
              QString info = "IP HOST = "+data->get_hosts()[i]->get_ip()+
                        "\nDOMAIN NAME ="+info_host->hostName()+"\n";
              QMessageBox::information(NULL,"Host Information",info+"\n"+data->get_hosts()[i]->print_packets());
         }
     }
}

void GUIp0f::search_host(){
    searched=true;
    network_db* data = network_db::get_istance();
    if(data->get_hosts().size()>0){
        delete_item();
        signal_buttons = new QSignalMapper(this);
        for(int i=0,row=0,column=0;i<data->get_hosts().size();i++){
            QString host_ip = data->get_hosts()[i]->get_ip();
            if(host_ip.indexOf(ui->lineEdit->text())!=-1){
                add_item_net(data->get_hosts()[i],row,column);
                if(column==4){
                    row++;
                    column=0;
                }else{
                    column++;
                }
             }
         }
        connect(signal_buttons, SIGNAL(mapped(const QString &)),
                     this, SIGNAL(clicked(const QString &)));
    }

}

void GUIp0f::delete_item(){
    ui->listWidget->clear();
    QLayoutItem* eliminate;
    while((eliminate = ui->gridLayout->takeAt(0))!=0){
        delete eliminate->widget();
    }
}

void GUIp0f::add_item_net(host *current_host, int row, int column){
    QString host_ip = current_host->get_ip();
    ui->listWidget->addItem(current_host->get_ip());
    QLabel *host_image=get_image_host(current_host);
    host_image->setFixedHeight(100);
    host_image->setFixedWidth(100);
    QPushButton *host_name=new QPushButton(host_ip);
    host_name->setFixedHeight(20);
    host_name->setFixedWidth(120);
    QFont font( "Arial", 11, QFont::Bold);
    host_name->setFont(font);
    connect(host_name, SIGNAL(clicked()), signal_buttons, SLOT(map()));
    signal_buttons->setMapping(host_name, host_ip);
    QGroupBox *my_group=new QGroupBox(ui->widget);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(host_image);
    vbox->addWidget(host_name);
    my_group->setLayout(vbox);
    my_group->show();
    my_group->setFixedHeight(130);
    my_group->setFixedWidth(130);
    ui->gridLayout->addWidget(my_group,row,column);
}


GUIp0f::~GUIp0f()
{
    delete ui;
}
