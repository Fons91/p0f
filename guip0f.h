#ifndef GUIP0F_H
#define GUIP0F_H

#include <QMainWindow>
#include <QComboBox>
#include <ui_guip0f.h>

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
    QString set_name_interface();

private:
    Ui::GUIp0f *ui;
    void create_list_interface();
};

#endif // GUIP0F_H
