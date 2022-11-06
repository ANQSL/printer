#include "client.h"
#include "QDialog"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QToolButton"
#include "QLineEdit"
#include "QFileDialog"
#include "QMessageBox"
#include "QDataStream"
#include "QFileInfo"
Client::Client(QObject *parent) : QObject(parent)
{
    init();
}

void  Client::getPrintFile()
{
   QStringList  filelist=QFileDialog::getOpenFileNames(NULL,
                                                      "选择文件",
                                                      "",
                                                      "PDF files(*.pdf) ");
   this->filelist+=filelist;
   emit(appendFileSignal(filelist));
}

void Client::sendFileName()
{
    QUrl file_url=filelist[index];
    QFileInfo info(file_url.toString());
    filename=info.fileName();
    filesize=info.size();
    QByteArray array;
    //文件名字帧
    array.append(char(0xBE));
    array.append(char(0x00));
    quint16 buf_len=filename.size()+5;
    array.append(char(buf_len>>8));
    array.append(char(buf_len));
    array.append(filename);
    array.append(char(0xEB));
    //发送数据
    socket->write(array);
}

void Client::sendFilData()
{
    QString file_path=filelist[index];
    QFile file(file_path);
    int sendsize=0;
    bool isok=file.open(QIODevice::ReadOnly);
    if(isok)
    {
        while(sendsize!=filesize)
        {
            QByteArray array;
            //文件数据帧
            array.append(char(0xBE));
            array.append(char(0x01));
            QByteArray data=file.read(1024*5);
            quint16 buf_len=data.size()+5;
            array.append(char(buf_len>>8));
            array.append(char(buf_len));
            array.append(data);
            array.append(char(0xEB));
            socket->write(array);
            sendsize+=data.size();
            int progress=(sendsize*100)/filesize;
            emit fileProgress(index,progress);
        }
    }
}

void Client::sendFileEnd()
{
   
}

void Client::sendFile()
{
  
}

void Client::removeFile(int index)
{
    this->filelist.removeAt(index);
}

QStringList Client::getPathFiles()
{
    return filelist;
}
void Client::init()
{
    initParameter();
    initConfig();
    setConnect();
}

void Client::initParameter()
{
    socket=new QTcpSocket();
}

void Client::initConfig()
{
    Config::readConfig();
    Config::Host host=Config::getServerConfig();
    this->setServer(host.ip,host.port);
}

void Client::setServer(QString ip, quint16 port)
{
    this->ip=ip;
    this->port=port;
}

void Client::setConnect()
{
    connect(this,&Client::printSignal,this,&Client::connectServer);
    connect(socket,&QTcpSocket::readyRead,this,&Client::accpetData);
}

void Client::connectServer()
{
    if(socket->state()==QAbstractSocket::UnconnectedState)
    {
       this->socket->connectToHost(this->ip,this->port);
    }
}

void Client::accpetData()
{
    
}
