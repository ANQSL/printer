#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "QQueue"
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

private slots:
    void appendSocket();
    void acceptData();
    void reSetSocket();//重新设置客户端
    void sendFileSingal();//向客户端发送发送文件信号
    void startPrintSlot();//开始打印文件
    void scoketError(QAbstractSocket::SocketError);
signals:
    void acceptDataFinish();//当前客户端数据接收完毕
    void startPrint();//开始打印
    void endPrint();//打印结束
private:
    void initParameter();
    void setConnect();
    void socketConnect();//当前客户端的信号连接
    void sendDataSingal();
    void acceptFileMsg();
    bool findBufHead();//查找帧头
    bool findFileEnd();//查找文件信息的帧尾
    void getFileMsg();
    void getFileData();//获取文件数据
    QTcpServer *server;//服务端
    QQueue<QTcpSocket *> sockets;//客户队列

    QTcpSocket *socket;//当前发送数据的客户端
    QByteArray data;//接收的数据
    typedef union filesize{
        qint64 size;
        char   data[8];
    }FileSize;
    FileSize filesize;
    QString filename;
};

#endif // SERVER_H
