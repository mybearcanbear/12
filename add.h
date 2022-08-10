#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include<QString>

namespace Ui {
class add;
}

class add : public QWidget
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = 0);
    ~add();
    int jiancha(QString xuehao);
    void writeToFile2(QString cnt);

private:
    Ui::add *ui;
    QList<QString> stu_lines;

public slots:
    void on_return_2_clicked();
    void on_add_2_clicked();
};

#endif // ADD_H
