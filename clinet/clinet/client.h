#ifndef CLIENT_H
#define CLIENT_H
#include "QTcpSocket"
#include <QObject>
#include "QUrl"
#include "config.h"
#include "encodedecode.h"
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

//    //创建设置打印文件目录窗口
//    void  createDialog(QWidget *parent=nullptr);
    void  getPrintFile();
    void  sendFileName();
    void  sendFilData();
    void  sendFileEnd();
    void  sendFile();
    void  removeFile(int index);
    QStringList getPathFiles();
public slots:
    void connectServer();
    void accpetData();
signals:
    void printSignal();
    void fileProgress(int,int);//文件上传进度
    void fileFinish();//文件传输完毕
    void appendFileSignal(QStringList);
private:
    //初始化
    void  init();
    void  initParameter();
    void  initConfig();
    void  setServer(QString,quint16);
    void  setConnect();
    QTcpSocket *socket;
    QUrl file_path;
    QString  ip;
    quint16  port;
    QStringList filelist;
    //此时上传的文件信息和文件
    QString filename;
    qint64  filesize;
    int index=0;//文件索引

    EncodeDecode encode;
};
#endif // CLIENT_H
