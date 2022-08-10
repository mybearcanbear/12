#ifndef QINGKUANG_H
#define QINGKUANG_H

#include <QWidget>

namespace Ui {
class qingkuang;
}

class qingkuang : public QWidget
{
    Q_OBJECT

public:
    explicit qingkuang(QWidget *parent = 0);
    ~qingkuang();

private:
    Ui::qingkuang *ui;
public slots:
    void on_xiugai_clicked();
    void on_return_2_clicked();
    void choose();
};

#endif // QINGKUANG_H
