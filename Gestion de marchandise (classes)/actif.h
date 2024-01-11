#ifndef ACTIF_H
#define ACTIF_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>

namespace Ui {
class actif;
}

class actif : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit actif(QWidget *parent = nullptr);
    ~actif();

private:
    Ui::actif *ui;
};

#endif // ACTIF_H
