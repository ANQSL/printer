#include "config.h"
#include "QFile"
#include "QJsonObject"
QJsonDocument Config::doc;
quint16 Config::port;
QString Config::temp_path;
Config::Config(QObject *parent) : QObject(parent)
{
}

void Config::initConfig()
{
    QFile file("./config/config.json");
    bool isok=file.open(QIODevice::ReadOnly);
    if(isok)
    {
       QByteArray data=file.readAll();
       Config::doc=QJsonDocument::fromJson(data);
       QJsonObject object=Config::doc.object();
       Config::temp_path=object.take("temp_path").toString();
       Config::port=object.take("server").toObject().take("port").toInt();
    }
    file.close();
}

void Config::setTempPath(QString path)
{
    Config::temp_path=path;
    QJsonObject object=Config::doc.object();
    object["temp_path"]=path;
    Config::doc.setObject(object);
    QByteArray data=Config::doc.toJson();
    QFile file("./config/config.json");
    bool isok=file.open(QIODevice::Truncate|QIODevice::WriteOnly);
    if(isok)
    {
        file.write(data);
    }
    file.close();
}

quint16 Config::getPort()
{
    return Config::port;
}

QString Config::getTempPath()
{
    return Config::temp_path;
}
