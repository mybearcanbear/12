#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include"chengyuan.h"
#include<QString>
#include<QIcon>

namespace Ui {
class manager;
}

class manager : public QWidget
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = 0);
    ~manager();
    chengyuan *Chengyuan;
    QList<QString> stu_lines;
    QString name1;
    void Name(QString name);
    QIcon btn_return;
    QIcon btn_qingkuang;
    QIcon btn_chengyuan;
    QIcon btn_shenqing;

private:
    Ui::manager *ui;

public slots:
    void on_qingkuang_clicked();
    void on_chengyuan_clicked();
    void on_huodong_clicked();
    void on_shenqing_clicked();

};

#endif // MANAGER_H
