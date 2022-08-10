#include "chengyuan.h"
#include "ui_chengyuan.h"
#include<QStandardItem>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QString>
#include<QDebug>
#include"manager.h"
#include"add.h"
#include"sub.h"

chengyuan::chengyuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chengyuan)
{
    ui->setupUi(this);
    if(readFromFile()==-1)
    {
        QMessageBox::critical(this,"错误","文件打开失败，请重试");
        this->close();
    }
    this->model=new QStandardItemModel;
    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("性别"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("部门"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("职务"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("班级"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("学号"));
    this->model->setHorizontalHeaderItem(6,new QStandardItem("联系方式"));
    this->ui->tableView->setModel(model);
    doit();
}

chengyuan::~chengyuan()
{
    delete ui;
}

int chengyuan::readFromFile()
{
    QFile file("E:\\kaifashijian\\kaifa\\成员信息.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return -1;
    }
    QTextStream in(&file);
    //in.setCodec("UTF-8");
    while(!in.atEnd()){
        QString line=in.readLine();
        stu_lines.append(line);
    }
    file.close();
    return 0;
}
void chengyuan::doit()
{
    int i=0;
    for(i=0;i<stu_lines.length();i++)
    {
        QString line=stu_lines.at(i);
        line=line.trimmed();
        QStringList subs=line.split(" ");
        this->model->setItem(i,0,new QStandardItem(subs.at(0)));
        this->model->setItem(i,1,new QStandardItem(subs.at(1)));
        this->model->setItem(i,2,new QStandardItem(subs.at(2)));
        this->model->setItem(i,3,new QStandardItem(subs.at(3)));
        this->model->setItem(i,4,new QStandardItem(subs.at(4)));
        this->model->setItem(i,5,new QStandardItem(subs.at(5)));
        this->model->setItem(i,6,new QStandardItem(subs.at(6)));
    }
}
void chengyuan::on_back_clicked()
{
    this->close();
    manager *p = new manager();
    p->show();
}
void chengyuan::on_add_clicked()
{
    this->close();
    add *p = new add();
    p->show();
}
void chengyuan::on_sub_clicked()
{
    this->close();
    sub *p=new sub();
    p->show();
}

void chengyuan::on_quanbu_clicked()
{
    doit();
}
void chengyuan::on_sousuo_clicked()
{
    QString xinxi;
    xinxi=ui->chaxun->text();
    int i=0,d=0,row=0;
    for(i=0;i<stu_lines.length();i++)
    {
        int j=0;
        QString line=stu_lines.at(i);
        line=line.trimmed();
        QStringList subs=line.split(" ");
        for(j=0;j<subs.length();j++)
        {
            if(xinxi==subs.at(j))
            {
                if(d==0){
                    this->model->removeRows(0, model->rowCount()); // 删除所有行
                    d=1;
                }
                this->model->setItem(row,0,new QStandardItem(subs.at(0)));
                this->model->setItem(row,1,new QStandardItem(subs.at(1)));
                this->model->setItem(row,2,new QStandardItem(subs.at(2)));
                this->model->setItem(row,3,new QStandardItem(subs.at(3)));
                this->model->setItem(row,4,new QStandardItem(subs.at(4)));
                this->model->setItem(row,5,new QStandardItem(subs.at(5)));
                this->model->setItem(row,6,new QStandardItem(subs.at(6)));
                row++;
            }
        }
    }
    if(d==0)
    {
        QMessageBox::critical(this,"错误","该信息不存在，请重新输入");
    }
}
