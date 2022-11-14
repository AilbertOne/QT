#include "shapewidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

ShapeWidget::ShapeWidget(QWidget *parent)
    : QWidget(parent)
{
    QPixmap pix;//新建一个QPixmap对象
    pix.load("16.png", 0, Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);
    resize(pix.size());
    setMask(QBitmap(pix.mask()));
}
void ShapeWidget::mousePressEvent(QMouseEvent *event){
    if(event ->button() == Qt::LeftButton){ //鼠标左键是否被按下，是则返回true
        dragPosition = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button() == Qt::RightButton)
        close();
}
void ShapeWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton){
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}

void ShapeWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap("16.png"));
}
ShapeWidget::~ShapeWidget()
{

}

