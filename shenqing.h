#ifndef SHENQING_H
#define SHENQING_H

#include <QWidget>

namespace Ui {
class shenqing;
}

class shenqing : public QWidget
{
    Q_OBJECT

public:
    explicit shenqing(QWidget *parent = 0);
    ~shenqing();

private:
    Ui::shenqing *ui;
public slots:
    void on_add_2_clicked();
    void on_return_2_clicked();
};

#endif // SHENQING_H
