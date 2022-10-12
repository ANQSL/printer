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
   this->filelist=filelist;
}

void Client::sendFileMsg()
{
    QUrl file_url=filelist[index];
    QFileInfo info(file_url.toString());
    filename=info.fileName();
    filesize=info.size();
    QByteArray array;
    array.append(char(0xBE));
    array.append(char(0xEB));
//    array.append(char(0x01));
    FileSize size;
    size.size=filesize;
//    array.append(size.data);
    array.append(filename);
    array.append(char(0xEB));
    array.append(char(0xBE));
    socket->write(array);
}

void Client::

sendFilData()
{
    QString file_path=filelist[index];
    QFile file(file_path);
    int sendsize=0;
    QByteArray array;
    //帧头
//    array.append(char(0xBC));
//    array.append(char(0xCB));
    //控制位
//    array.append(char(0x01));
    socket->write(array);
    bool isok=file.open(QIODevice::ReadOnly);
//    qDebug()<<file_path;
    if(isok)
    {
        while(sendsize!=filesize)
        {
           QByteArray array=file.read(1024*10);
           socket->write(array);
           sendsize+=array.size();
           int progress=(sendsize*100)/filesize;
           emit fileProgress(index,progress);
        }
    }
    array.clear();
//    array.append(char(0xCB));
//    array.append(char(0xBC));
    socket->write(array);
}

void Client::sendFileEnd()
{
    QByteArray array;
    array.append(char(0xBE));
    array.append(char(0xEB));
    array.append(char(0xEB));
    array.append(char(0xBE));
    socket->write(array);
}

void Client::sendFile()
{
    if(index<filelist.size())
    {
        sendFileMsg();
        sendFilData();
        sendFileEnd();
        index++;
    }
    else
    {
        socket->disconnectFromHost();
        index=0;
        emit fileFinish();
    }
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

//void Client::createDialog(QWidget *parent)
//{
//    QDialog *dialog=new QDialog(parent);
//    dialog->setModal(true);
//    dialog->setWindowTitle("文件选择");
//    //文件显示和文件选择
//    QLineEdit *file_path=new QLineEdit();
//    file_path->setEnabled(false);
//    QToolButton *open_dir=new QToolButton();
//    open_dir->setText("浏览");
//    //文件显示和文件选择布局
//    QHBoxLayout *hbox=new QHBoxLayout();
//    hbox->addStretch(1);
//    hbox->addWidget(file_path,6);
//    hbox->addWidget(open_dir,1);
//    hbox->addStretch(1);
//    //文件打印按钮布局
//    QToolButton *print=new QToolButton();
//    print->setText("打印");
//    QHBoxLayout *hbox2=new QHBoxLayout();
//    hbox2->addStretch(1);
//    hbox2->addWidget(print,1);
//    hbox2->addStretch(1);
//    QVBoxLayout *vbox=new QVBoxLayout();
//    //界面整体布局
//    vbox->addStretch(2);
//    vbox->addLayout(hbox,2);
//    vbox->addStretch(1);
//    vbox->addLayout(hbox2,2);
//    vbox->addStretch(2);
//    dialog->setLayout(vbox);

//    //信号与处理
//    connect(open_dir,&QToolButton::clicked,[=](bool checked){
//        QUrl path=QFileDialog::getOpenFileUrl();
//        if(!path.isEmpty())
//        {
//            file_path->setText(path.fileName());
//            this->file_path=path;
//        }

//    });
//    connect(print,&QToolButton::clicked,[=](bool checked){
//        if(!this->file_path.isEmpty())
//        {
//            emit  printSignal();
//            delete file_path;
//            delete open_dir;
//            delete print;
//            delete dialog;
//        }
//        else {
//            QMessageBox::about(dialog,"消息","请选择文件");
//        }
//    });
//    dialog->show();
//}

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
    QByteArray data=socket->readAll();
    QByteArray array;
    array.append(char(0xEB));
    array.append(char(0xBE));
    if(data==array)
    {
        qDebug()<<"发送下一个文件";
        sendFile();
    }
}
