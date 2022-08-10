#include "qingkuang.h"
#include "ui_qingkuang.h"
#include"manager.h"
#include<QMessageBox>

qingkuang::qingkuang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qingkuang)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/image/user.jpg").scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
    ui->listWidget->setCurrentRow(0);
    QString str;
    QString a1="沈阳航空航天大学“兴科协会”";
    QString a2="以创新为追求点，以求真为成功的支点，以唯美为更高的起点，自成立以来，一直致力于举办“高水平，强质量”的科技类活动 。";
    str = a1+"\n"+a2;
    ui->textEdit->setText(str);
    connect(ui->listWidget,&QListWidget::itemClicked, [&]{
        choose();
    });
}

qingkuang::~qingkuang()
{
    delete ui;
}
void qingkuang::on_return_2_clicked()
{
    this->close();
    manager *p=new manager();
    p->show();
}
void qingkuang::on_xiugai_clicked()
{
    QMessageBox::question(this,"请确认信息",ui->textEdit->toPlainText(),"确认","取消");
}
void qingkuang::choose()
{
    if(ui->listWidget->currentItem()->text()=="社团简介"){
        QString str;
        QString a1="沈阳航空航天大学“兴科协会”";
        QString a2="以创新为追求点，以求真为成功的支点，以唯美为更高的起点，自成立以来，一直致力于举办“高水平，强质量”的科技类活动 。";
        str = a1+"\n"+a2;
        ui->textEdit->setText(str);
    }
    else if(ui->listWidget->currentItem()->text()=="社团成员"){
        QString str;
        QString a1="负责人：王意航";
        QString a2="负责人电话：13125689456";
        QString a3="成员：12人";
        str = a1+"\n"+a2+"\n"+a3;
        ui->textEdit->setText(str);
    }
    else if(ui->listWidget->currentItem()->text()=="社团服务范围"){
        QString str="举办“高水平，强质量”的科技类活动，为了更好地服务在校学生。";
        ui->textEdit->setText(str);
    }
    else if(ui->listWidget->currentItem()->text()=="社团活动"){
        QString str;
        QString a1="活动一：";
        QString a2="活动二：";
        str = a1+"\n"+a2;
        ui->textEdit->setText(str);
    }
}
