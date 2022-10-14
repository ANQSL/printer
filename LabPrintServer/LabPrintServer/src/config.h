#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include "QJsonDocument"
class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = nullptr);
    static void initConfig();
    static void setTempPath(QString path);
    static quint16 getPort();
    static QString getTempPath();
signals:
private:
    static QJsonDocument doc;
    static quint16 port;
    static QString temp_path;
};

#endif // CONFIG_H
