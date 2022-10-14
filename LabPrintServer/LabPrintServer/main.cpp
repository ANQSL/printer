#include "widget.h"
#include <QApplication>
#include "src/config.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Config::initConfig();
    Widget w;
    w.show();
    return a.exec();
}
