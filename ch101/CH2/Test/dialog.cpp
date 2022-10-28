#include "dialog.h"
#include "ui_dialog.h"
#include <QtGui>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}"); //正则表达式限制输入字元的范围

    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textChanged()));

}

void Dialog::on_lineEdit_textChanged()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

Dialog::~Dialog()
{
    delete ui;
}

