#ifndef GUIP0F_H
#define GUIP0F_H

#include <QMainWindow>
#include <QComboBox>
#include <ui_guip0f.h>
#include "mythread.h"
#include "network_db.h"
#include <QTimer>
#include "host.h"

namespace Ui {
class GUIp0f;
}

class GUIp0f : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GUIp0f(QWidget *parent = 0);
    ~GUIp0f();
public slots:
    void set_name_interface();
    void stop_p0f();
    void update_gui();
    void see_info_host();

private:
    QLabel *get_image_host(host *ip);
    void set_list_ip();
    Ui::GUIp0f *ui;
    void create_list_interface();
    MyThread my;
    QTimer* timer_update;




};

#endif // GUIP0F_H
