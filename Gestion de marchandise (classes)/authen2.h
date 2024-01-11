#ifndef AUTHEN2_H
#define AUTHEN2_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class authen2;
}

class authen2 : public QDialog
{
    Q_OBJECT

public:
      QSqlDatabase db;
    explicit authen2(QWidget *parent = nullptr);
    ~authen2();

private slots:
    void on_connecter_clicked();

private:
    Ui::authen2 *ui;
};

#endif // AUTHEN2_H
