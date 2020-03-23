#ifndef HOTKEY_H
#define HOTKEY_H

#include <QMainWindow>
/*-----------------------------------*/
//key
#include <QHotkey>
//debug
#include <QDebug>
//beep
#include <beep.h>
/*----------------------------------*/

namespace Ui {
class HotKey;
}

class HotKey : public QMainWindow
{
    Q_OBJECT

public:
    explicit HotKey(QWidget *parent = 0);
    ~HotKey();

private slots:
    void hot_key();

private:
    Ui::HotKey *ui;
    QHotkey *gp_hotkey;
};

#endif // HOTKEY_H
