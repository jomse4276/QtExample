#include "keyevent.h"
#include "ui_keyevent.h"

KeyEvent::KeyEvent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KeyEvent)
{
    ui->setupUi(this);
}

KeyEvent::~KeyEvent()
{
    delete ui;
}

/*----------------------------------------------------------------
 *          Event
 * ---------------------------------------------------------------*/
void KeyEvent::keyPressEvent(QKeyEvent *event)
{
    /*------------------------------
     *  #define Q_C_Do Beep(262,200);
        #define Q_D_Re Beep(294,200);
        #define Q_E_Mi Beep(330,200);
        #define Q_F_Fa Beep(349,200);
        #define Q_G_So Beep(392,200);
        #define Q_A_La Beep(440,200);
        #define Q_B_Si Beep(523,200);
     *
     * ---------------------------*/
    switch (event->key()) {
    case Qt::Key_1:
        Q_C_Do;
        break;
    case Qt::Key_2:
        Q_D_Re;
        break;
    case Qt::Key_3:
        Q_E_Mi;
        break;
    case Qt::Key_4:
        Q_F_Fa;
        break;
    case Qt::Key_5:
        Q_G_So;
        break;
    case Qt::Key_6:
        Q_A_La;
        break;
    case Qt::Key_7:
        Q_B_Si;
        break;
    default:
        break;
    }
}
