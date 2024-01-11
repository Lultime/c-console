#ifndef COMPTEVENTE_H
#define COMPTEVENTE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class comptevente;
}

class comptevente : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit comptevente(QWidget *parent = nullptr);
    ~comptevente();

private:
    Ui::comptevente *ui;
};

#endif // COMPTEVENTE_H
