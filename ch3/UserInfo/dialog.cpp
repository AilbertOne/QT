#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UserInfo"));
    /*****************左侧*****************/
    UserNameLabel = new QLabel(tr("用户名："));
    UserNameLineEdit = new QLineEdit;
    NameLabel = new QLabel(tr("姓名："));
    NameLineEdit = new QLineEdit;
    SexLabel = new QLabel(tr("性别："));
    SexCombobox = new QComboBox;
    SexCombobox -> addItem(tr("女"));
    SexCombobox -> addItem(tr("男"));
    DepartmentLabel = new QLabel(tr("部门："));
    DepartmentTextEdit = new QTextEdit;
    AgeLabel = new QLabel(tr("年龄："));
    AgeLineEdit = new QLineEdit;
    OtherLabel = new QLabel(tr("备注："));
    OtherLabel -> setFrameStyle(QFrame::Panel|QFrame::Sunken); //设置控件风格
    LeftLayout = new QGridLayout(); //左侧布局
    //向布局中加入需要布局的控件
    LeftLayout -> addWidget(UserNameLabel, 0, 0); //用户名
    LeftLayout -> addWidget(UserNameLineEdit, 0, 1);
    LeftLayout -> addWidget(NameLabel, 1,0); //姓名
    LeftLayout -> addWidget(NameLineEdit, 1, 1);
    LeftLayout -> addWidget(SexLabel, 2, 0); //性别
    LeftLayout -> addWidget(SexCombobox, 2, 1);
    LeftLayout -> addWidget(DepartmentLabel, 3, 0); //部门
    LeftLayout -> addWidget(DepartmentTextEdit, 3, 1);
    LeftLayout -> addWidget(AgeLabel, 4, 0); //年龄
    LeftLayout -> addWidget(AgeLineEdit, 4, 1);
    LeftLayout -> addWidget(OtherLabel, 4, 0); //其它
    LeftLayout -> setColumnStretch(0,1);
    LeftLayout -> setColumnStretch(1, 3); //设定两列比为1:3

    /*********右侧*********/
    HeadLabel = new QLabel(tr("头像："));
    HeadIconLabel = new QLabel;
    QPixmap icon("1.png");
    HeadIconLabel -> setPixmap(icon);
    HeadIconLabel -> resize(icon.width(), icon.height());
    UpdateHeadBtn = new QPushButton(tr("更新"));

    //完成右上侧头像选择区的布局
    ToprightLayout = new QHBoxLayout();
    ToprightLayout -> setSpacing(20);
    ToprightLayout -> addWidget(HeadLabel);
    ToprightLayout -> addWidget(HeadIconLabel);
    ToprightLayout -> addWidget(UpdateHeadBtn);
    IntroductionLabel = new QLabel(tr("个人说明：")); //右下部分
    IntroductionTextEdit = new QTextEdit;

}

Dialog::~Dialog()
{

}
