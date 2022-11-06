#include "QCoreApplication"
#include "server/server.h"
#include "server/config.h"
int main(int argv,char** args)
{
    QCoreApplication app(argv,args);
    Config::initConfig();
    Server server;
    return app.exec();
}