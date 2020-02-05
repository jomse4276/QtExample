#ifndef PORT_H
#define PORT_H

/*********user define**********************************************/

/*******************************************************************/

#include <QMainWindow>

/**********user include**********************************************/
//box
#include <QMessageBox>

//port
#include <QSerialPort>
#include <QIODevice>

//data
#include <QByteArray>

//debug
#include <QDebug>
/********************************************************/

namespace Ui {
class Port;
}

class Port : public QMainWindow
{
    Q_OBJECT

public:
    explicit Port(QWidget *parent = 0);
    ~Port();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(int index);

    void open_port(bool);
    void close_port(bool);
    void port_send(bool);
    void receive_data();
    void display_clear(bool);

    void help_about(bool);

private:
    Ui::Port *ui;
    void system_init();
    void port_config();

    QSerialPort global_port;

};

#endif // PORT_H
