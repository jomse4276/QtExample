#include "hotkey.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HotKey w;
    w.show();

    return a.exec();
}
