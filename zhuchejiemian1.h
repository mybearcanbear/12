#ifndef ZHUCHEJIEMIAN1_H
#define ZHUCHEJIEMIAN1_H

#include <QWidget>

namespace Ui {
class zhuchejiemian1;
}

class zhuchejiemian1 : public QWidget
{
    Q_OBJECT

public:
    explicit zhuchejiemian1(QWidget *parent = 0);
    ~zhuchejiemian1();
    void writeToFile2(QString cnt);
    int jiancha(QString name,QString account);

private:
    Ui::zhuchejiemian1 *ui;

private slots:
    void on_yes_clicked();
    void on_return_2_clicked();

};

#endif // ZHUCHEJIEMIAN1_H
