#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include<manager.h>
#include<zhucejiemian.h>
#include<user.h>
#include<QString>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    manager *Manager;
    zhucejiemian *zhucezhanghao;
    user *User;
    QString name;
    int readFile2(QString account,QString password);
    int readFile3(QString account,QString password);

public slots:
 void on_manager_clicked();
 void on_user_clicked();
 void on_zhuce_clicked();
 void on_zhuce1_clicked();
};

#endif // MAINWINDOW_H
