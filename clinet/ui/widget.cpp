#include "widget.h"
Widget::Widget(QWidget *parent):QWidget(parent)
{
    init();
    setWidgetLayout();
    setConnect();
    setSize(600,400);
}
Widget::~Widget()
{

}
void Widget::init()
{
    select=new QPushButton();
    select->setText("选择文件");
    printer=new QPushButton();
    printer->setText("打印");
    listwidget=new QListWidget();
    btn_group=new QHBoxLayout();
    widget_layout=new QVBoxLayout();
}
void Widget::setWidgetLayout()
{
    btn_group->addStretch(6);
    btn_group->addWidget(select,1);
    btn_group->addWidget(printer,1);
    widget_layout->addWidget(listwidget);
    widget_layout->addLayout(btn_group);
    this->setLayout(widget_layout);
}
void Widget::setConnect()
{
    connect(select,&QPushButton::clicked,this,&Widget::selectSlot);
    connect(printer,&QPushButton::clicked,this,&Widget::printSlot);
    connect(&clinet,&Client::appendFileSignal,this,&Widget::appendFile);
}
void Widget::selectSlot(bool checked)
{
    clinet.getPrintFile();
}
void Widget::printSlot(bool checked)
{

}
void Widget::appendFile(QStringList filelist)
{
    if(!filelist.empty())
    {
        for(int i=0;i<filelist.size();i++)
        {
            QFileInfo info(filelist[i]);
            QListWidgetItem *item=new QListWidgetItem();
            FileProgress *fileprogress=new FileProgress(info.fileName());
            fileprogress->setSize(listwidget->width(),20);
            item->setSizeHint(fileprogress->size());
            listwidget->addItem(item);
            listwidget->setItemWidget(item,fileprogress);
        }
    }
}
void Widget::setSize(int w,int h)
{
    this->setFixedSize(w,h);
}