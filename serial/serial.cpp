#include "serial.h"
#include "ui_serial.h"

Serial::Serial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Serial)
{
    ui->setupUi(this);
    //user
    system_init();
}

Serial::~Serial()
{
    delete ui;
}

/*--------------------------------------------------------------------------
 *          funtions
 * -------------------------------------------------------------------------*/
void Serial::system_init()
{
    //port config
    global_port.setParity(QSerialPort::NoParity);
    global_port.setDataBits(QSerialPort::Data8);
    global_port.setStopBits(QSerialPort::OneStop);

    //connect
    connect(ui->btn_open,&QPushButton::clicked,this,&Serial::btn_open_port);
    connect(ui->btn_close,&QPushButton::clicked,this,&Serial::btn_close_port);
    connect(ui->btn_send,&QPushButton::clicked,this,&Serial::btn_send_data);
    connect(&global_port,&QSerialPort::readyRead,this,&receive_data);
}
/*--------------------------------------------------------------------------
 *          slots
 * -------------------------------------------------------------------------*/
void Serial::btn_open_port(bool)
{
    /*--------port name------------------------*/
    qDebug()<<ui->cmb_port_name->currentIndex();//printf 0
//    int i = 10;
//    qDebug("%d",i);
    switch (ui->cmb_port_name->currentIndex()) {
    case 0:
        global_port.setPortName("COM1");
        break;
    case 1:
        global_port.setPortName("COM2");
        break;
    case 2:
        global_port.setPortName("COM3");
        break;
    case 3:
        global_port.setPortName("COM4");
        break;
    case 4:
        global_port.setPortName("COM5");
        break;
    case 5:
        global_port.setPortName("COM6");
        break;
    case 6:
        global_port.setPortName("COM7");
        break;
    default:
         global_port.setPortName("COM8");
        break;
    }
    /*--------baud rate-----------------------------*/
    switch (ui->cmb_baud_rate->currentIndex()) {
    case 0:
        global_port.setBaudRate(QSerialPort::Baud115200);
        break;
    case 1:
        global_port.setBaudRate(QSerialPort::Baud57600);
        break;
    case 2:
        global_port.setBaudRate(QSerialPort::Baud38400);
        break;
    case 3:
        global_port.setBaudRate(QSerialPort::Baud19200);
        break;
    case 4:
        global_port.setBaudRate(QSerialPort::Baud9600);
        break;
    case 5:
        global_port.setBaudRate(QSerialPort::Baud4800);
        break;
    case 6:
        global_port.setBaudRate(QSerialPort::Baud2400);
        break;
    default:
        global_port.setBaudRate(QSerialPort::Baud1200);
        break;
    }
    //open
    global_port.open(QIODevice::ReadWrite);
    ui->lab_status->setText("Connected");
    //test
//    global_port.write("1");
}
void Serial::btn_close_port(bool)
{
    ui->lab_status->setText("Disconnected");
    global_port.close();
}
/*------------sending data---------------------*/
void Serial::btn_send_data(bool)
{
   QString data = ui->lint_send_data->text();
   QByteArray array = data.toLatin1();//QString--->QByteArray
   global_port.write(array);
}
/*-----------receive data-----------------*/
void Serial::receive_data()
{
   QByteArray array = global_port.readAll();
   qDebug()<<array;
   if(ui->checkBox->checkState() == Qt::Checked){
      ui->plainTextEdit->insertPlainText(QString(array.toHex(' ').toUpper().append(' ')));
   }else {
       ui->plainTextEdit->insertPlainText(QString(array));
   }
}
