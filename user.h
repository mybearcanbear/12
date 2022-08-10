#ifndef USER_H
#define USER_H

#include <QWidget>
#include<QTableWidget>
#include<QString>
#include<QVBoxLayout>

namespace Ui {
class user;
}

class user : public QWidget
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = 0);
    ~user();
    void Account(QString account);
    QString account1;
    int xunzhao();
    int weizhi;
    QVBoxLayout* myLayout2 = new QVBoxLayout();

private:
    Ui::user *ui;

private slots:
    void choose();
    void on_in_clicked();
    void on_out_clicked();
    void on_return_2_clicked();

signals:

};

#endif // USER_H
