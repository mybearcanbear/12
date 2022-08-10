#include "sub.h"
#include "ui_sub.h"
#include"chengyuan.h"
#include<QString>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>

sub::sub(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sub)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/image/user.jpg").scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
}

sub::~sub()
{
    delete ui;
}
void sub::on_sub_2_clicked()
{
    QString xuehao = ui->le_xuehao->text();
    if(xuehao.length()<1)
    {
        QMessageBox::critical(this,"错误","信息填写不完整，请重新检查","确定");
    }
    else{
        jiancha(xuehao);
    }
}
void sub::on_return_2_clicked()
{
    this->close();
    chengyuan *p=new chengyuan();
    p->show();
}
void sub::jiancha(QString xuehao)
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
    int i=0,d=0;
    for(i=0;i<stu_lines.length();i++)
    {
        QString line=stu_lines.at(i);
        line=line.trimmed();
        QStringList subs=line.split(" ");
        if(xuehao==subs.at(5))
        {
            int j=0;
            d++;
            QString content;
            for(j=0;j<subs.length();j++)
            {
                content=content+subs.at(j)+'\n';
            }
            int ret=QMessageBox::question(this,"请确认信息",content,"确认","取消");
            if(ret==0){
                QFile file1("E:\\kaifashijian\\kaifa\\成员信息.txt");
                if(!file1.open(QIODevice::WriteOnly | QIODevice::Truncate))
                {
                    QMessageBox::critical(this,"错误","文件打开失败，信息没有保存","确认");
                    return;
                }
                QTextStream in(&file1);
                int h=0;
                for(h=0;h<stu_lines.length();h++)
                {
                    if(h!=i)
                    {
                        in<<stu_lines.at(h)+'\n';
                    }
                }
                file1.close();
                QMessageBox msgBox;
                msgBox.setWindowTitle("提示");
                msgBox.setText("删除成功");
                msgBox.exec();
            }
        }
    }
    if(d==0){
        QMessageBox::critical(this,"错误","未查询到此人，请重新输入","确认");
    }
}
