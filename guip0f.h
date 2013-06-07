#ifndef GUIP0F_H
#define GUIP0F_H

#include <QMainWindow>

namespace Ui {
class GUIp0f;
}

class GUIp0f : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GUIp0f(QWidget *parent = 0);
    ~GUIp0f();
    
private:
    Ui::GUIp0f *ui;
};

#endif // GUIP0F_H
