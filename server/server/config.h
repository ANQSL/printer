#ifndef CONFIG_H
#define CONFIG_H
#include "QJsonDocument"
class Config 
{
public:
    explicit Config();
    static void initConfig();
    static void setTempPath(QString path);
    static quint16 getPort();
    static QString getTempPath();
private:
    static QJsonDocument doc;
    static quint16 port;
    static QString temp_path;
};

#endif // CONFIG_H
