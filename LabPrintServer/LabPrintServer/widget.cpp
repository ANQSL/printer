#include "widget.h"
#include "ui_widget.h"
#include "src/config.h"
#include "QFileDialog"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->fIle_dir->setText(Config::getTempPath());
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString dir=QFileDialog::getExistingDirectory(NULL);
    ui->fIle_dir->setText(dir);
    Config::setTempPath(dir);
}
