#ifndef CONTACT_H
#define CONTACT_H
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QWidget>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = nullptr);

signals:

public slots:
private:
    QLabel *EmailLabel;
    QLineEdit *EmailLineEdit;
    QLabel *AddrLabel;
    QLineEdit *AddrLineEdit;
    QLabel *CodeLabel;
    QLineEdit *CodeLineEdit;
    QLabel *MoviTelLabel;
    QLineEdit *MoviTeLineEdit;
    QCheckBox *MoviTeCheckBook;
    QLabel *ProTelLabel;
    QLineEdit *ProTelLineEdit;
    QGridLayout *MainLayout;
};

#endif // CONTACT_H
