#include "zhucejiemian.h"
#include "ui_zhucejiemian.h"
#include"mainwindow.h"
#include<QString>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QDebug>

zhucejiemian::zhucejiemian(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zhucejiemian)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/image/user.jpg").scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
}

zhucejiemian::~zhucejiemian()
{
    delete ui;
}
void zhucejiemian::on_yes_clicked()
{
    QString account = ui->account->text();//获取账号
    QString password = ui->password->text();//获取密码
    QString password2 = ui->password_2->text();//获取确认密码
    if(jiancha(account)==1)
    {
        QMessageBox::critical(this,"错误","账号已经存在，请重新输入","确认");
    }
    else
    {
        if(password!=password2)
        {
            QMessageBox::critical(this,"错误","两次输入的密码不一致，请检查后重新输入","确认");
        }
        else if(account==NULL||password==NULL||password2==NULL)
        {
            QMessageBox::critical(this,"错误","信息填写不全，请检查后重新输入","确认");
        }
        else if(password==password2)
        {
            QString content=account+" "+password+" "+password2+"\n";
            writeToFile2(content);//将信息写入文件；
            QMessageBox msgBox;
            msgBox.setText("注册成功.");
            msgBox.exec();
            this->close();
            MainWindow *p = new MainWindow();
            p->show();

        }
    }
}
void zhucejiemian::on_return_2_clicked()
{
    this->close();
    MainWindow *p = new MainWindow();
    p->show();
}
void zhucejiemian::writeToFile2(QString cnt)
{
    QFile file("E:\\kaifashijian\\kaifa\\注册信息.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有保存","确认");
        return ;
    }
    QTextStream out(&file);
    out<<cnt;
    file.close();
}
int zhucejiemian::jiancha(QString account)
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
        if(account==subs.at(0))
        {
            return 1;
        }
    }
    return 0;
}

