#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "src/client.h"
#include "QListWidgetItem"
#include "src/fileprogress.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void  setConnect();
private slots:
    void deletePrintFile(int index);
    void setProgress(int,int);
    //清除所有的文件
    void clearFile();
    void on_open_dir_clicked();

    void on_print_clicked();

private:

    //设置文件删除的连接信号
    void setItemConnect(FileProgress *);
    //向file_list插入需要打印的文件
    void appendFile();
    Ui::Widget *ui;
    Client clinet;
    QList<QListWidgetItem *> listitem;
};
#endif // WIDGET_H
