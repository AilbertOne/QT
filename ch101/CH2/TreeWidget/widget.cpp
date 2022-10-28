#include "widget.h"
#include "ui_widget.h"
//#include <QCheckBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();

    connect(ui->treeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(treeItemChanged(QTreeWidgetItem*,int)));
}
void Widget::init()
{
    ui->treeWidget->clear();
    QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
    item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    item->setCheckState(0,Qt::Checked);
    item->setText(0,"group");

    QTreeWidgetItem* item1 = new QTreeWidgetItem(item);
    item1->setText(0,"group1");
    item1->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled |Qt::ItemIsSelectable);
    item1->setCheckState(0,Qt::Checked);

    QTreeWidgetItem* subItem1 = new QTreeWidgetItem(item1);
    subItem1->setText(0,"subItem1");
    subItem1->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem1->setCheckState(0,Qt::Checked);

    QTreeWidgetItem* subItem2 = new QTreeWidgetItem(item1);
    subItem2->setText(0,"subItem2");
    subItem2->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem2->setCheckState(0,Qt::Checked);

    QTreeWidgetItem* subItem3 = new QTreeWidgetItem(item1);
    subItem3->setText(0,"subItem3");
    subItem3->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem3->setCheckState(0,Qt::Checked);

    QTreeWidgetItem* subItem4 = new QTreeWidgetItem(item1);
    subItem4->setText(0,"subItem4");
    subItem4->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem4->setCheckState(0,Qt::Checked);

    QTreeWidgetItem* item2 = new QTreeWidgetItem(item);
    item2->setText(0,"group2");
    item2->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled |Qt::ItemIsSelectable);
    item2->setCheckState(0,Qt::Checked);

    QTreeWidgetItem* subItem21 = new QTreeWidgetItem(item2);
    subItem21->setText(0,"subItem21");
    subItem21->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem21->setCheckState(0,Qt::Checked);

    QTreeWidgetItem* subItem22 = new QTreeWidgetItem(item2);
    subItem22->setText(0,"subItem22");
    subItem22->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem22->setCheckState(0,Qt::Checked);

    QTreeWidgetItem* subItem23 = new QTreeWidgetItem(item2);
    subItem23->setText(0,"subItem23");
    subItem23->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem23->setCheckState(0,Qt::Checked);

    QTreeWidgetItem* subItem24 = new QTreeWidgetItem(item2);
    subItem24->setText(0,"subItem24");
    subItem24->setFlags(Qt::ItemIsUserCheckable |Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem24->setCheckState(0,Qt::Checked);
}
void Widget::updateParentItem(QTreeWidgetItem* item)
{
    QTreeWidgetItem* parent = item->parent();
    if(parent == NULL)
    {
        return;
    }
    //选中的子节点个数
    int selectCount =0;
    int childCount=parent->childCount();
    for(int i=0;i<childCount;i++)
    {
        QTreeWidgetItem* childItem = parent->child(i);
        if(childItem->checkState(0)== Qt::Checked)
        {
            selectCount++;
        }
    }
    if(selectCount<=0)
    {
        //未选中状态
        parent->setCheckState(0,Qt::Unchecked);

    }
    else if(selectCount>0 && selectCount <childCount)
    {
        //部分选中状态
        parent->setCheckState(0,Qt::PartiallyChecked);
    }
    else if(selectCount == childCount)
    {
        //全选状态
        parent->setCheckState(0,Qt::Checked);
    }
}
void Widget::treeItemChanged(QTreeWidgetItem* item,int column)
{
    QString itemCheck = item->text(0);
    //选中时
    if(Qt::Checked == item->checkState(0))
    {
        QTreeWidgetItem* parent= item->parent();
        int count = item->childCount();
        if(count>0)
        {
            for(int i=0;i<count;i++)
            {
                //子节点也选中
                item->child(i)->setCheckState(0,Qt::Checked);
            }
        }
        else
        {
            //是子节点
            updateParentItem(item);
        }
    }
    else if(Qt::Unchecked == item->checkState(0))
    {
        int count = item->childCount();
        if(count>0)
        {
            for(int i=0;i<count;i++)
            {
                item->child(i)->setCheckState(0,Qt::Unchecked);
            }
        }
        else
        {
           updateParentItem(item);
        }
    }
}
Widget::~Widget()
{
    delete ui;
}

