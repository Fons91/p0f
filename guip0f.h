#ifndef GUIP0F_H
#define GUIP0F_H

#include <QMainWindow>
#include <QComboBox>
#include <ui_guip0f.h>
#include "mythread.h"
#include "network_db.h"
#include <QTimer>
#include "host.h"
#include <QString>
#include <QSignalMapper>

namespace Ui {
class GUIp0f;
}

class GUIp0f : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GUIp0f(QWidget *parent = 0);
    ~GUIp0f();
signals:
    void clicked(const QString &ip_host);
public slots:
    void set_name_interface();
    void stop_p0f();
    void update_gui();
    void see_info_host(QString host_ip);
    void search_host();


private:
    bool searched;
    MyThread my;
    QTimer* timer_update;
    QSignalMapper *signal_buttons;
    Ui::GUIp0f *ui;
    QLabel *get_image_host(host *ip);
    void set_list_ip();
    void create_list_interface();
    void delete_item();
    void add_item_net(host* current_host, int row, int column);





};

#endif // GUIP0F_H
