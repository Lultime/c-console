#ifndef COMPTEACHAT_H
#define COMPTEACHAT_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class compteachat;
}

class compteachat : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit compteachat(QWidget *parent = nullptr);
    ~compteachat();

private:
    Ui::compteachat *ui;
};

#endif // COMPTEACHAT_H
