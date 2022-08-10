#ifndef CHENGYUAN_H
#define CHENGYUAN_H

#include <QWidget>
#include<QStandardItem>
#include<QString>

namespace Ui {
class chengyuan;
}

class chengyuan : public QWidget
{
    Q_OBJECT

public:
    explicit chengyuan(QWidget *parent = 0);
    ~chengyuan();
    int readFromFile();
    void doit();

private:
    Ui::chengyuan *ui;
    QStandardItemModel *model;
    QList<QString> stu_lines;

public slots:
    void on_add_clicked();
    void on_sub_clicked();
    void on_back_clicked();
    void on_quanbu_clicked();
    void on_sousuo_clicked();

};

#endif // CHENGYUAN_H
