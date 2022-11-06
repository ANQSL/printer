#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "QQueue"
#include "QPrinterInfo"
#include "windows.h"
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
private slots:
    void appendSocket();
    void acceptData();
    void reSetSocket();//重新设置客户端
    void sendFileSingal();//向客户端发送发送文件信号
    void startPrintSlot();//开始打印文件
    void scoketError(QAbstractSocket::SocketError);
    void setSaveFalg(bool falg);
signals:
    void acceptDataFinish();//当前客户端数据接收完毕
    void startPrint();//开始打印
    void endPrint();//打印结束
private:
    void initParameter();
    void setConnect();
    void socketConnect();//当前客户端的信号连接
    QTcpServer *server;//服务端
    QQueue<QTcpSocket *> sockets;//客户队列

    QTcpSocket *socket;//当前发送数据的客户端
    QByteArray data;//接收的数据
    QByteArray filedata;//文件数据
    QString filename;
    bool save_falg;//文件是否存储标志
};

#endif // SERVER_H
