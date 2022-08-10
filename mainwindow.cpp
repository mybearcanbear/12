#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QMessageBox>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<manager.h>
#include<zhucejiemian.h>
#include<user.h>
#include"zhuchejiemian1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/image/user.jpg").scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_manager_clicked()
{
    QString account = ui->account->text();//用户账号
    QString password = ui->password->text();//用户密码
    int s=readFile3(account,password);
    if(s==1)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setText("管理员登录成功");
        msgBox.exec();
        this->close();
        Manager = new manager();
        Manager->show();
        Manager->Name(name);
    }
    if(s==0)
    {
        QMessageBox msgBox2;
        msgBox2.setWindowTitle("提示");
        msgBox2.setText("管理员登录失败，请重新输入信息");
        msgBox2.exec();
    }
}
void MainWindow::on_user_clicked()
{
    QString account = ui->account->text();//获取用户账号
    QString password = ui->password->text();//获取用户密码
    int s=readFile2(account,password);
    if(s==1)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setText("用户登录成功");
        msgBox.exec();
        this->close();
        User = new user();
        User->show();
        User->Account(account);
    }
    if(s==0)
    {

        QMessageBox msgBox2;
        msgBox2.setWindowTitle("提示");
        msgBox2.setText("用户登录失败，请重新输入信息");
        msgBox2.exec();

    }
}
void MainWindow::on_zhuce_clicked()
{
    this->close();
    zhucezhanghao = new zhucejiemian();
    zhucezhanghao->show();
}
void MainWindow::on_zhuce1_clicked()
{
    this->close();
    zhuchejiemian1 *p = new zhuchejiemian1();
    p->show();
}

int MainWindow::readFile2(QString account, QString password)
{
    QList<QString> stu_lines;
    QFile file("E:\\kaifashijian\\kaifa\\注册信息.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有保存","确认");
        return 0;
    }
    QTextStream in(&file);
    while(!in.atEnd())

    {
        QString line=in.readLine();
        stu_lines.append(line);
    }
    file.close();
    int i=0;
    for(i=0;i<stu_lines.length();i++)
    {
        QString line=stu_lines.at(i);
        line=line.trimmed();
        QStringList subs=line.split(" ");
        if(account==subs.at(0)&&password==subs.at(1))
        {
            return 1;
        }
    }
    return 0;
}
int MainWindow::readFile3(QString account, QString password)
{
    QList<QString> stu_lines;
    QFile file("E:\\kaifashijian\\kaifa\\注册信息1.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有保存","确认");
        return 0;
    }
    QTextStream in(&file);
    while(!in.atEnd())

    {
        QString line=in.readLine();
        stu_lines.append(line);
    }
    file.close();
    int i=0;
    for(i=0;i<stu_lines.length();i++)
    {
        QString line=stu_lines.at(i);
        line=line.trimmed();
        QStringList subs=line.split(" ");
        if(account==subs.at(1)&&password==subs.at(2))
        {
            name=subs.at(0);
            return 1;
        }
    }
    return 0;
}
