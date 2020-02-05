#include "port.h"
#include "ui_port.h"

/**********************************************************************************************
 * SerialPort:
 *      1.Config
 *        2.Sending
 *          3.Receive
 * ******************************************************************************************/

Port::Port(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Port)
{
    ui->setupUi(this);
    //user
    system_init();
}

Port::~Port()
{
    delete ui;
}

/*----------------------------------------------------------------------------------------
 *              Funtion
 * --------------------------------------------------------------------------------------*/
void Port::system_init()
{
    //config
    port_config();

    //connect
    connect(ui->actionAbout,&QAction::triggered,this,&Port::help_about);
    connect(ui->btn_open,&QPushButton::clicked,this,&Port::open_port);
    connect(ui->btn_close,&QPushButton::clicked,this,&Port::close_port);
    connect(ui->btn_send,&QPushButton::clicked,this,&Port::port_send);
    connect(&global_port,SIGNAL(readyRead()),this,SLOT(receive_data()));
    connect(ui->btn_clear,&QPushButton::clicked,this,&Port::display_clear);
}

void Port::port_config()
{
    /*--------------------------------------------------------
     *port config
     *  1.Setting ParityBits is "None"
     *  2.Setting DataBits is "8"
     *  3.Setting StopBits is "1"
     * ------------------------------------------------------*/
    global_port.setParity(QSerialPort::NoParity);
    global_port.setDataBits(QSerialPort::Data8);
    global_port.setStopBits(QSerialPort::OneStop);
}
/*----------------------------------------------------------------------------------------
 *              Slots
 * --------------------------------------------------------------------------------------*/
/*************menu slots*************************/
void Port::help_about(bool)
{
    QMessageBox box;
    box.about(this,"About","Author:Jomse Qin<br>\
                            qq:2468690029<br>\
                            qq group:769579637");
}
/***********************************************/
/***********port config slots*******************/
void Port::on_comboBox_activated(const QString &arg1)
{
    qDebug()<<arg1;
    global_port.setPortName(arg1);
}

void Port::on_comboBox_2_activated(int index)
{
    global_port.setBaudRate(index);
}

void Port::open_port(bool)
{
//    qDebug()<<"open";
    global_port.open(QIODevice::ReadWrite);
    ui->lab_status->setText("Status:Connected");
}

void Port::close_port(bool)
{
    global_port.close();
    ui->lab_status->setText("Status:Disconnected");
}
/***********ending config slots*********************/
/***********sending data by port********************/
void Port::port_send(bool)
{

    QString str = ui->ledit_send->text();
    QByteArray array = str.toLatin1();
    qDebug()<<"str"<<str;
    global_port.write(array);
}
/***********ending to send data********************/
/***********receive data***************************/
void Port::receive_data()
{
    QByteArray data = global_port.readAll();
    ui->plainTextEdit->insertPlainText(data);
    qDebug()<<"data:"<<data;
}
/***********ending receive*************************/
/***********display funtion slots******************/
void Port::display_clear(bool)
{
    ui->plainTextEdit->clear();
}
/**************************************************/
