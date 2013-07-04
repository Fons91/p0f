#include "guip0f.h"
#include "ui_guip0f.h"


GUIp0f::GUIp0f(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GUIp0f)
{

    ui->setupUi(this);
}

void GUIp0f::create_list(){

        ui->create_list_interface();

}

GUIp0f::~GUIp0f()
{
    delete ui;
}
