#include "widget.h"
#include "ui_widget.h"
#include "QFileInfo"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setConnect();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setConnect()
{
    connect(&clinet,&Client::fileFinish,this,&Widget::clearFile);
}
void Widget::deletePrintFile(int index)
{
    QListWidgetItem *item=ui->file_list->item(index);
    FileProgress *fileprogress=(FileProgress *)(ui->file_list->itemWidget(item));
    delete  fileprogress;
    ui->file_list->removeItemWidget(item);
    this->listitem.removeAt(index);
    this->clinet.removeFile(index);
    delete item;
}

void Widget::clearFile()
{
    int count=ui->file_list->count();
    for(int i=0;i<count;i++)
    {
        QListWidgetItem *item=ui->file_list->item(0);
        QWidget *widget=ui->file_list->itemWidget(item);
        delete widget;
        ui->file_list->removeItemWidget(item);
        this->listitem.removeAt(0);
        delete item;
    }
}

void Widget::setItemConnect(FileProgress * fileProgress)
{
    connect(fileProgress,&FileProgress::deleteSingal,this,&Widget::deletePrintFile);
    connect(&clinet,&Client::fileProgress,this,&Widget::setProgress);
}

void Widget::appendFile()
{
    QStringList filelist=clinet.getPathFiles();
    if(!filelist.empty())
    {
        for (int i=0;i<filelist.size();i++) {
            QListWidgetItem *item=new QListWidgetItem();
            FileProgress *fileprogress=new FileProgress();
            //设置progress初始化数据,文件名字和索引号和信号
            QFileInfo info(filelist[i]);
            fileprogress->setFilename(info.fileName());
            fileprogress->setIndex(i);
            setItemConnect(fileprogress);
            //将窗口添加到listWidget
            ui->file_list->addItem(item);
            ui->file_list->setItemWidget(item,fileprogress);
            //将子控件插入listitem
            this->listitem.append(item);
        }

    }
}
void Widget::setProgress(int index, int value)
{
    QListWidgetItem *item=ui->file_list->item(index);
    FileProgress *fileprogress=(FileProgress *)(ui->file_list->itemWidget(item));
    fileprogress->setProgress(value);
}

void Widget::on_open_dir_clicked()
{
    clinet.getPrintFile();
    appendFile();
}

void Widget::on_print_clicked()
{
    clinet.connectServer();
}
