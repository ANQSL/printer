#ifndef FILEPROGRESS_H
#define FILEPROGRESS_H
#include "QWidget"
#include "QLabel"
#include "QProgressBar"
#include "QToolButton"
#include "QHBoxLayout"
#include "QSpinBox"
class FileProgress:public QWidget
{
    Q_OBJECT
private:
    /* data */
    QLabel filename;
    QProgressBar progress;
    QToolButton  delete_file;
    QSpinBox      spinbox;
    QHBoxLayout  *layout;
    void setWidgetLayout();
public:
    explicit FileProgress(QWidget *parent=nullptr);
    FileProgress(QString filename);
    void setSize(int w,int h);
    ~FileProgress();
    int getFileNum();
    void setProgress(int value);
};
#endif