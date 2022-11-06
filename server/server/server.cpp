#include "server.h"
#include "QFile"
#include "QTextDocument"
#include "QCoreApplication"
#include "config.h"
Server::Server(QObject *parent) : QObject(parent)
{
    initParameter();
    setConnect();
    quint16 port=Config::getPort();
    this->server->listen(QHostAddress::Any,port);
}
Server::~Server()
{
    
}
void Server::initParameter()
{
    server=new QTcpServer();
}
void Server::setConnect()
{
    connect(server,&QTcpServer::newConnection,this,&Server::appendSocket);
    connect(this,&Server::acceptDataFinish,this,&Server::reSetSocket);
    connect(this,&Server::startPrint,this,&Server::startPrintSlot);
    connect(this,&Server::endPrint,this,&Server::sendFileSingal);
}

void Server::socketConnect()
{
    connect(socket,&QTcpSocket::readyRead,this,&Server::acceptData);
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(scoketError(QAbstractSocket::SocketError)));
}
void Server::appendSocket()
{
    qDebug()<<"new connection";
    if(server->hasPendingConnections())
    {
        if(this->sockets.empty())
        {
            this->socket=server->nextPendingConnection();
            socketConnect();
            sendFileSingal();//向客户端发送发送数据的信号
        }
        else
        {
            QTcpSocket *socket=server->nextPendingConnection();
            this->sockets.enqueue(socket);//进队
        }
    }
}
void Server::acceptData()
{
    qDebug()<<socket->readAll();
}
void Server::reSetSocket()
{

    //断开数据传输完成的客户端
//    qDebug()<<"下一个客户端";
    //队列为空就不操作
    if(!this->sockets.isEmpty())
    {
        this->socket=this->sockets.dequeue();
        //如果此时socket断开则重新获取socket
        if(socket->state()==QAbstractSocket::UnconnectedState)
        {
            emit acceptDataFinish();
        }
        else
        {
            socketConnect();
            sendFileSingal();//向客户端发送发送数据的信号
        }
    }
}

void Server::sendFileSingal()
{
}
void Server::startPrintSlot()
{
}

void Server::scoketError(QAbstractSocket::SocketError error)
{
    if(QAbstractSocket::RemoteHostClosedError==error)
    {
        reSetSocket();
    }
}

void Server::setSaveFalg(bool falg)
{
    this->save_falg=falg;
}