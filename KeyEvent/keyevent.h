#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QMainWindow>

/*-------user include-------------*/
//event
#include <QKeyEvent>
//debug
#include <QDebug>

//beep
#include <beep.h>
/*---------------------------------*/

namespace Ui {
class KeyEvent;
}

class KeyEvent : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeyEvent(QWidget *parent = 0);
    ~KeyEvent();

private:
    Ui::KeyEvent *ui;

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // KEYEVENT_H
