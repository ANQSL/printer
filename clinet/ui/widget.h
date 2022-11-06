#ifndef WIDGET_H
#define WIDGET_H
#include "QWidget"
#include "QPushButton"
#include "QListWidget"
#include "QVBoxLayout"
#include  "QHBoxLayout"
#include  "client.h"
#include  "fileprogress.h"
#include "QFileInfo"
class Widget: public QWidget
{
    Q_OBJECT
private:
    /* data */
    QPushButton *select;
    QPushButton *printer;
    QListWidget *listwidget;
    QVBoxLayout *widget_layout;
    QHBoxLayout *btn_group;
    Client clinet;
    void init();
    void setWidgetLayout();
    void setConnect();
    void setSize(int w,int h);
public slots:
    void selectSlot(bool);
    void printSlot(bool);
    void appendFile(QStringList);
public:
    explicit Widget(QWidget *parent=nullptr);
    ~Widget();
};
#endif