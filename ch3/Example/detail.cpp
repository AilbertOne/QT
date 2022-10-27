#include "detail.h"

Detail::Detail(QWidget *parent) : QWidget(parent)
{
    NationalLabel =new QLabel(tr("国家/地址"));
    NationalComboBox = new QComboBox;
    NationalComboBox -> insertItem(0, tr("中国"));
    NationalComboBox -> insertItem(1, tr("美国"));
    NationalComboBox -> insertItem(2, tr("英国"));
    ProvinceLabel = new QLabel(tr("省份："));
    ProvinceComBox = new QComboBox;
    ProvinceComBox -> insertItem(0, tr("江苏省"));
    ProvinceComBox -> insertItem(1, tr("山东省"));
    ProvinceComBox -> insertItem(2, tr("浙江省"));
    CityLabel = new QLabel(tr("城市："));
    CityLineEdit = new QLineEdit;
    IntroductLabel = new QLabel(tr("个人说明："));
    IntroductTextEdit = new QTextEdit;
    mainLayout = new QGridLayout(this);
    mainLayout -> setMargin(15);
    mainLayout -> setSpacing(10);
    mainLayout -> addWidget(NationalLabel, 0, 0);
    mainLayout -> addWidget(NationalComboBox, 0,1);
    mainLayout -> addWidget(ProvinceLabel, 1, 0);
    mainLayout -> addWidget(ProvinceComBox, 1, 1);
    mainLayout -> addWidget(CityLabel, 2, 1);
    mainLayout -> addWidget(CityLineEdit, 2, 1);
    mainLayout -> addWidget(IntroductLabel, 3, 0);
    mainLayout -> addWidget(IntroductTextEdit, 3, 1);

}