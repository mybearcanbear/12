#ifndef SUB_H
#define SUB_H

#include <QWidget>

namespace Ui {
class sub;
}

class sub : public QWidget
{
    Q_OBJECT

public:
    explicit sub(QWidget *parent = 0);
    ~sub();
    void jiancha(QString xuehao);
    QList<QString> stu_lines;

private:
    Ui::sub *ui;

public slots:
    void on_sub_2_clicked();
    void on_return_2_clicked();

};

#endif // SUB_H
