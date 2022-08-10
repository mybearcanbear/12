#ifndef ZHUCEJIEMIAN_H
#define ZHUCEJIEMIAN_H

#include <QWidget>

namespace Ui {
class zhucejiemian;
}

class zhucejiemian : public QWidget
{
    Q_OBJECT

public:
    explicit zhucejiemian(QWidget *parent = 0);
    ~zhucejiemian();
     void writeToFile2(QString cnt);
     int jiancha(QString account);
private:
    Ui::zhucejiemian *ui;

private slots:
    void on_yes_clicked();
    void on_return_2_clicked();

signals:
};

#endif // ZHUCEJIEMIAN_H
