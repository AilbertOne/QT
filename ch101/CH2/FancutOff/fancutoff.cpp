#include "fancutoff.h"
#include "ui_fancutoff.h"

fancutoff::fancutoff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fancutoff)
{
    ui->setupUi(this);
}

fancutoff::~fancutoff()
{
    delete ui;
}
