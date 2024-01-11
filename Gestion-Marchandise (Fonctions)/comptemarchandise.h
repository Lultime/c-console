#ifndef COMPTEMARCHANDISE_H
#define COMPTEMARCHANDISE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class comptemarchandise;
}

class comptemarchandise : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit comptemarchandise(QWidget *parent = nullptr);
    ~comptemarchandise();

private:
    Ui::comptemarchandise *ui;
};

#endif // COMPTEMARCHANDISE_H
