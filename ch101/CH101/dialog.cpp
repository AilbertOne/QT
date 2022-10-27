#include "dialog.h"
#include "ui_dialog.h"
#define PI 3.1415926

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_countBtn_clicked()
{
    bool ok;
    QString tempstr;
    QString valueStr = ui->radiuslineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * PI; //计算圆面积
    ui->areaLabel_2->setText(tempstr.setNum(area));
}
