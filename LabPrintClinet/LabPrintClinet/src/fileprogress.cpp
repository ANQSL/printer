#include "fileprogress.h"
#include "ui_fileprogress.h"
#include "QDebug"
FileProgress::FileProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileProgress)
{
    ui->setupUi(this);
    ui->horizontalLayout->setStretch(0,10);
    ui->horizontalLayout->setStretch(1,10);
    ui->horizontalLayout->setStretch(2,1);
    this->delete_flag=false;
}

FileProgress::~FileProgress()
{
    delete ui;
}

void FileProgress::setFilename(QString filename)
{
    ui->fillename->setText(filename);
}

void FileProgress::setProgress(int value)
{
    ui->progressBar->setValue(value);
}

bool FileProgress::checkDelete()
{
    return this->delete_flag;
}

void FileProgress::setIndex(int index)
{
    this->index=index;
}

void FileProgress::on_pushButton_clicked()
{
    this->delete_flag=true;
    emit deleteSingal(index);
}
