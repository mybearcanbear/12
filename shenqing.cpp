#include "shenqing.h"
#include "ui_shenqing.h"
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include"user.h"

shenqing::shenqing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shenqing)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/image/user.jpg").scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
}

shenqing::~shenqing()
{
    delete ui;
}
void shenqing::on_add_2_clicked()
{
    QString name=this->ui->le_xingming->text();//获取姓名
    QString sex;
        if(this->ui->sex->isChecked())
        {
            sex="男";
        }
        else
        {
            sex="女";
        }
    QString bumen = ui->cb_bumen->currentText();
    QString zhiwu = ui->cb_zhiwu->currentText();
    QString banji = ui->le_banji->text();
    QString xuehao = ui->le_xuehao->text();
    QString lianxi = ui->le_lianxi->text();
    QString content = name+'\n'+sex+'\n'+bumen+'\n'+zhiwu+'\n'+banji+'\n'+xuehao+'\n'+lianxi;
    QString cnt = name+' '+sex+' '+bumen+' '+zhiwu+' '+banji+' '+xuehao+' '+lianxi+' ';
    if(name.length()<1||sex.length()<1||bumen.length()<1||zhiwu.length()<1||banji.length()<1||xuehao.length()<1||lianxi.length()<1){
        QMessageBox::critical(this,"错误","信息填写不完整，请重新检查","确定");

    }
    else{
        int ret=QMessageBox::question(this,"请确认信息",content,"确认","取消");
        if(ret==0){
            QFile file("E:\\kaifashijian\\kaifa\\加入申请.txt");
            if(!file.open(QIODevice::Append|QIODevice::Text))
            {
                QMessageBox::critical(this,"错误","文件打开失败，信息没有保存","确认");
            }
            QTextStream out(&file);
            out<<cnt;
            file.close();
        }
    }
}
void shenqing::on_return_2_clicked()
{
    this->close();
    user *p = new user();
    p->show();
}
