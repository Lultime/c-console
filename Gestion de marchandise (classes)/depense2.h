#ifndef DEPENSE2_H
#define DEPENSE2_H

#include <QDialog>

namespace Ui {
class lister;
}

class lister : public QDialog
{
    Q_OBJECT

public:
    explicit lister(QWidget *parent = nullptr);
    ~lister();

private:
    Ui::lister *ui;
};

#endif // DEPENSE2_H
