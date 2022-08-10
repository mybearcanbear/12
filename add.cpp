#include "add.h"
#include "ui_add.h"
#include"chengyuan.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QDebug>

add::add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/image/user.jpg").scaled(this->size());
    QPalette palette;
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
}

add::~add()
{
    delete ui;
}

void add::on_return_2_clicked()
{
    this->close();
    chengyuan *p = new chengyuan();
    p->show();
}
void add::on_add_2_clicked()
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
    QString cnt = name+' '+sex+' '+bumen+' '+zhiwu+' '+banji+' '+xuehao+' '+lianxi+'\n';
    if(name.length()<1||sex.length()<1||bumen.length()<1||zhiwu.length()<1||banji.length()<1||xuehao.length()<1||lianxi.length()<1){
        QMessageBox::critical(this,"错误","信息填写不完整，请重新检查","确定");

    }
    else{
        if(jiancha(xuehao)==1)
        {
            int ret=QMessageBox::question(this,"请确认信息",content,"确认","取消");
            if(ret==0)
            {
                writeToFile2(cnt);
                QMessageBox msgBox;
                msgBox.setWindowTitle("提示");
                msgBox.setText("添加成功");
                msgBox.exec();
            }
        }
    }
}
int add::jiancha(QString xuehao)
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
        if(xuehao==subs.at(5))
        {
            QMessageBox::critical(this,"错误","该用户已存在","确认");
            return 0;
        }
    }
    return 1;
}
void add::writeToFile2(QString cnt)
{
    QFile file("E:\\kaifashijian\\kaifa\\成员信息.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有保存","确认");
        return ;
    }
    QTextStream out(&file);
    out<<cnt;
    file.close();
}
