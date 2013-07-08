#include "guip0f.h"
#include "ui_guip0f.h"
#include <QDebug>
#include <QNetworkInterface>



GUIp0f::GUIp0f(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUIp0f)
{

    ui->setupUi(this);
}

QString GUIp0f::set_name_interface(){

   qDebug()<< QString(ui->list_interface->currentText());
   return ui->list_interface->currentText();
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
