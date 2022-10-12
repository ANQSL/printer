#include "server.h"
#include "QFile"
Server::Server(QObject *parent) : QObject(parent)
{
    initParameter();
    setConnect();
    this->server->listen(QHostAddress::LocalHost,7777);
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

void Server::sendDataSingal()
{

}

void Server::acceptFileMsg()
{

}

bool Server::findBufHead()
{
    QByteArray buf_head;
    buf_head.append(char(0xBE));
    buf_head.append(char(0xEB));
    if(data.contains(buf_head))
    {
        return 1;
    }
    buf_head.clear();
    buf_head.append(char(0xBC));
    buf_head.append(char(0xCB));
    if(data.contains(buf_head))
    {
        return 2;
    }
    return 0;
}

bool Server::findFileEnd()
{
    QByteArray array;
    array.append(char(0xBE));
    array.append(char(0xEB));
    array.append(char(0xEB));
    array.append(char(0xBE));
    if(data.contains(array))
    {
      for(int i=0;i<data.size();i++)
      {
          if(data[i]==char(0xBE)&&data[i+1]==char(0xEB)&&data[i+2]==char(0xEB)&&data[i+3]==char(0xBE))
          {
              QFile file(filename);
              file.open(QIODevice::WriteOnly);
              file.close();
              file.open(QIODevice::Append);
              file.write(data.left(i));
              file.close();
              data.remove(0,i+3);
              qDebug()<<"文件传输结束";
              emit startPrint();
          }
      }
      return false;
    }
    else
    {
        return true;
    }
}
void Server::getFileMsg()
{
    for(int i=0;i<data.size();i++)
    {
        if(data[i]==char(0xBE)&&data[i+1]==char(0xEB))
        {
            i+=2;
            QByteArray array;
            for(;i<data.size()&&data[i]!=char(0xEB)&&data[i+1]!=char(0xBE);i++)
            {
                array.append(data[i]);
            }
            filename=QString(array);
            qDebug()<<filename;
            data.remove(0,i+1);
            break;
        }
    }
}

void Server::getFileData()
{
    if(findFileEnd())
    {
        QFile file(filename);
        file.open(QIODevice::WriteOnly);
        file.close();
        file.open(QIODevice::Append);
        file.write(data);
        file.close();
    }
}
void Server::appendSocket()
{
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
    data+=socket->readAll();
    bool head=findBufHead();
    if(head&&filename.isEmpty())
    {
        getFileMsg();
    }
    if(!filename.isEmpty())
    {
        getFileData();
    }


}
void Server::reSetSocket()
{

    //断开数据传输完成的客户端
    qDebug()<<"下一个客户端";
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
    QByteArray array;
    array.append(char(0xEB));
    array.append(char(0xBE));
    socket->write(array);
}

void Server::startPrintSlot()
{
    qDebug()<<"开始打印文件";
    QFile::remove(filename);
    filename="";
    emit endPrint();
}

void Server::scoketError(QAbstractSocket::SocketError error)
{
    if(QAbstractSocket::RemoteHostClosedError==error)
    {
        reSetSocket();
    }
}

