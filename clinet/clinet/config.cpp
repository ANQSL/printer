#include "config.h"
#include "QJsonDocument"
#include "QFile"
#include "QJsonObject"
#include "QDebug"
Config::Host Config::host;
Config::Config(QObject *parent) : QObject(parent)
{
}

void Config::readConfig()
{
    QFile file(".../config/config.json");
    bool isok=file.open(QIODevice::ReadOnly);
    if(isok)
    {
        QByteArray array=file.readAll();
        QJsonDocument doc=QJsonDocument::fromJson(array);
        Config::configServer(doc);
    }
    file.close();
}

Config::Host Config::getServerConfig()
{
    return Config::host;
}

void Config::configServer(QJsonDocument doc)
{
    QJsonObject object=doc.object();
    QJsonValue value=object.take("server");
    object=value.toObject();
    Config::host.ip=object.take("host").toString();
    Config::host.port=object.take("port").toInt();
//    qDebug()<<Config::host.ip;
//    qDebug()<<Config::host.port;

}
