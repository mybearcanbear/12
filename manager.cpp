#include "manager.h"
#include "ui_manager.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QString>
#include<QDebug>
#include<QLabel>
#include"chengyuan.h"
#include"qingkuang.h"
#include"mainwindow.h"

manager::manager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/image/user.jpg").scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);

    btn_chengyuan.addPixmap(QPixmap(":/image/people.jpg"));
    ui->chengyuan->setIcon(btn_chengyuan);
    ui->chengyuan->setIconSize(QSize(200, 200));
    btn_qingkuang.addPixmap(QPixmap(":/image/情况.jpg"));
    ui->qingkuang->setIcon(btn_qingkuang);
    ui->qingkuang->setIconSize(QSize(200, 200));
    btn_shenqing.addPixmap(QPixmap(":/image/申请.jpg"));
    ui->shenqing->setIcon(btn_shenqing);
    ui->shenqing->setIconSize(QSize(200, 200));
    btn_return.addPixmap(QPixmap(":/image/返回.jpg"));
    ui->huodong->setIcon(btn_return);
    ui->huodong->setIconSize(QSize(200, 200));
}

manager::~manager()
{
    delete ui;
}

void manager::Name(QString name)
{
    name1=name;
}

void manager::on_qingkuang_clicked()
{
    this->close();
    qingkuang *p = new qingkuang();
    p->show();
}

void manager::on_chengyuan_clicked()
{
    Chengyuan = new chengyuan();
    Chengyuan->show();
    this->close();
}

void manager::on_huodong_clicked()
{
    this->close();
    MainWindow *p=new MainWindow();
    p->show();
}
void manager::on_shenqing_clicked()
{
    QFile file("E:\\kaifashijian\\kaifa\\成员信息.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有保存","确认");
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())

    {
        QString line=in.readLine();
        stu_lines.append(line);
    }
    file.close();
    for(int i=0;i<2;i++)
    {
        QString content;
        QString line=stu_lines.at(i);
        line=line.trimmed();
        QStringList subs=line.split(" ");
        for(int j=0;j<subs.length();j++)
        {
            content=content+subs.at(j)+'\n';
        }
        QMessageBox::question(this,"申请加入",content,"同意","不同意");
    }
    for(int i=2;i<4;i++)
    {
        QString content;
        QString line=stu_lines.at(i);
        line=line.trimmed();
        QStringList subs=line.split(" ");
        for(int j=0;j<subs.length();j++)
        {
            content=content+subs.at(j)+'\n';
        }
        QMessageBox::question(this,"申请退出",content,"同意","不同意");
    }
}
