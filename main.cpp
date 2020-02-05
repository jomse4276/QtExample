#include "port.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Port w;
    w.show();

    return a.exec();
}
