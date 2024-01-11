#ifndef COMPTEDEPENSE_H
#define COMPTEDEPENSE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class comptedepense;
}

class comptedepense : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit comptedepense(QWidget *parent = nullptr);
    ~comptedepense();

private:
    Ui::comptedepense *ui;
};

#endif // COMPTEDEPENSE_H
