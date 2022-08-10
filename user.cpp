#include "user.h"
#include "ui_user.h"
#include<QDebug>
#include<QTableWidget>
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<manager.h>
#include<QTextCodec>
#include<QLabel>
#include<QVBoxLayout>
#include"shenqing.h"
#include"mainwindow.h"

user::user(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/image/user.jpg").scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
    QList<QString> stu_lines;
    QFile file("E:\\kaifashijian\\kaifa\\社团名称.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有保存","确认");
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");//读取中文
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
        ui->comboBox->addItem(line);
    }

    ui->listWidget->setCurrentRow(0);
    QString str;
    QString a1="沈阳航空航天大学“兴科协会”";
    QString a2="以创新为追求点，以求真为成功的支点，以唯美为更高的起点，自成立以来，一直致力于举办“高水平，强质量”的科技类活动 。";
    str = a1+"\n"+a2;
    ui->textBrowser->insertPlainText(str);
    connect(ui->listWidget,&QListWidget::itemClicked, [&]{
        choose();
    });
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(choose()));
}
user::~user()
{
    delete ui;
}

void user::on_in_clicked()
{
    if(xunzhao()==2)
    {
        QMessageBox::critical(this,"错误","该用户已在该社团","确认");
    }
    if(xunzhao()==1)
    {
        this->close();
        shenqing *p = new shenqing();
        p->show();
    }
}

void user::on_out_clicked()
{
    if(xunzhao()==1)
    {
        QMessageBox::critical(this,"错误","该用户不在该社团","确认");
    }
    if(xunzhao()==2)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("提示");
        msgBox.setText("提交申请成功");
        msgBox.exec();
    }
}

int user::xunzhao()
{
    QList<QString> stu_lines;
    QFile file("E:\\kaifashijian\\kaifa\\成员信息.txt");
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
        int j=0;
        for(j=0;j<subs.length();j++)
        {
            if(account1==subs.at(j))
            {
                return 2;
            }
        }
    }
    return 1;
}

void user::Account(QString account)
{
    account1=account;
}

void user::choose()
{
    QList<QString> stu_lines;
    QFile file("E:\\kaifashijian\\kaifa\\社团信息.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有保存","确认");
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");//读取中文
    while(!in.atEnd())
    {
        QString line=in.readLine();
        stu_lines.append(line);
    }
    file.close();
    int i=0,a[6],d=0;
    for(i=0;i<stu_lines.length();i++)
    {
        QString line=stu_lines.at(i);
        line=line.trimmed();
        //QStringList subs=line.split(" ");
        //a=stu_lines.at(0);
        if(line==ui->comboBox->currentText())
        {
            d=1;
            a[0]=i;
        }
        else if(d==1&&line=="社团简介")
        {
            a[1]=i;
        }
        else if(d==1&&line=="社团成员")
        {
            a[2]=i;
        }
        else if(d==1&&line=="社团服务范围")
        {
            a[3]=i;
        }
        else if(d==1&&line=="社团活动")
        {
            a[4]=i;
        }
        else if(d==1&&line=="结束")
        {
            a[5]=i;
            d=0;
        }
    }
    for(i=0;i<6;i++)
    {
        QString line=stu_lines.at(a[i]);
        line=line.trimmed();
        if(line==ui->listWidget->currentItem()->text())
        {
            ui->textBrowser->clear();
            int j=0;
            for(j=a[i]+1;j<a[i+1];j++)
            {
                QString line=stu_lines.at(j);
                ui->textBrowser->insertPlainText(line);
                ui->textBrowser->insertPlainText("\n");
            }
            break;
        }
    }
}
void user::on_return_2_clicked()
{
    this->close();
    MainWindow *p = new MainWindow();
    p->show();
}
