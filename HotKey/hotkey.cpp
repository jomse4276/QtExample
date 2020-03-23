#include "hotkey.h"
#include "ui_hotkey.h"

HotKey::HotKey(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HotKey)
{
    ui->setupUi(this);
    //user
    gp_hotkey = new QHotkey(QKeySequence("Ctrl+K"),true,this);
    connect(gp_hotkey,&QHotkey::activated,this,&HotKey::hot_key);
}

HotKey::~HotKey()
{
    delete ui;
}

/*--------------------------------------------
 *      slots
 * ------------------------------------------*/
void HotKey::hot_key()
{
    qDebug()<<"hhhh";
    Q_G_So;
}
