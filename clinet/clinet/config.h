#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
class Config : public QObject
{
public:
    explicit Config(QObject *parent = nullptr);
    typedef  struct host{
        QString ip;
        quint16 port;
    }Host;
    static void readConfig();
    static Config::Host getServerConfig();
private:
    static Host host;

    static void configServer(QJsonDocument);
};

#endif // CONFIG_H
