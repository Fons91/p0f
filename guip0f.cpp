#include "guip0f.h"
#include "ui_guip0f.h"
#include <QDebug>



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


GUIp0f::~GUIp0f()
{
    delete ui;
}
