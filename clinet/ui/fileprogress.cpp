#include "fileprogress.h"
FileProgress::FileProgress(QWidget *parent):QWidget(parent)
{

}
FileProgress::FileProgress(QString filename)
{
    setWidgetLayout();
    this->filename.setText(filename);
}
FileProgress::~FileProgress()
{
}
void FileProgress::setWidgetLayout()
{
    this->layout=new QHBoxLayout();
    layout->addWidget(&filename,2);
    layout->addWidget(&progress,2);
    layout->addWidget(&spinbox,1);
    layout->addWidget(&delete_file,1);
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);
}
void FileProgress::setSize(int w,int h)
{
    this->setFixedSize(w,h);
}
int FileProgress::getFileNum()
{
    return spinbox.value();
}
void FileProgress::setProgress(int value)
{
    progress.setValue(value);
}