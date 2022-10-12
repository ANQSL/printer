#ifndef FILEPROGRESS_H
#define FILEPROGRESS_H

#include <QWidget>

namespace Ui {
class FileProgress;
}

class FileProgress : public QWidget
{
    Q_OBJECT

public:
    explicit FileProgress(QWidget *parent = nullptr);
    ~FileProgress();
    void setFilename(QString);
    bool checkDelete();
    void setIndex(int index);
public slots:
    void setProgress(int);
signals:
    void deleteSingal(int index);
private slots:
    void on_pushButton_clicked();
private:
    Ui::FileProgress *ui;
    bool delete_flag;
    int index;//在文件顺序的编号
};

#endif // FILEPROGRESS_H
