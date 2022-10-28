#ifndef FANCUTOFF_H
#define FANCUTOFF_H

#include <QDialog>

namespace Ui {
class fancutoff;
}

class fancutoff : public QDialog
{
    Q_OBJECT

public:
    explicit fancutoff(QWidget *parent = nullptr);
    ~fancutoff();

private:
    Ui::fancutoff *ui;
};

#endif // FANCUTOFF_H
