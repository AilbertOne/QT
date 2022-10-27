#include "contact.h"

Contact::Contact(QWidget *parent) : QWidget(parent)
{
    EmailLabel = new QLabel(tr("电子邮件："));
    EmailLineEdit = new QLineEdit;
    AddrLabel = new QLabel(tr("联系地址："));
    AddrLineEdit = new QLineEdit;
    CodeLabel = new QLabel(tr("邮政编码："));
    CodeLineEdit = new QLineEdit;
    MoviTelLabel = new QLabel(tr("移动电话："));
    MoviTeLineEdit = new QLineEdit;
    MoviTeCheckBook = new QCheckBox(tr("接收留言"));
    ProTelLabel = new QLabel(tr("办公电话："));
    ProTelLineEdit = new QLineEdit;
    MainLayout = new QGridLayout(this);
    MainLayout -> setMargin(15);
    MainLayout -> setSpacing(10);
    MainLayout ->addWidget(EmailLabel, 0, 0);
    MainLayout -> addWidget(EmailLineEdit, 0, 1);
    MainLayout -> addWidget(AddrLabel, 1, 0);
    MainLayout -> addWidget(AddrLineEdit, 1, 1);
    MainLayout -> addWidget(CodeLabel, 2, 0);
    MainLayout -> addWidget(CodeLineEdit, 2, 1);
    MainLayout ->addWidget(MoviTelLabel, 3, 0);
    MainLayout -> addWidget(MoviTeLineEdit, 3, 1);
    MainLayout -> addWidget(MoviTeCheckBook, 3, 2);
    MainLayout -> addWidget(ProTelLabel, 4, 0);
    MainLayout ->addWidget(ProTelLineEdit, 4, 1);
    MainLayout -> setSizeConstraint(QLayout::SetFixedSize);
}
