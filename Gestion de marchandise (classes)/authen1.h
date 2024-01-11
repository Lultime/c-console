#ifndef AUTHEN1_H
#define AUTHEN1_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class authen1;
}

class authen1 : public QDialog
{
    Q_OBJECT

public:
      QSqlDatabase db;
    explicit authen1(QWidget *parent = nullptr);
    ~authen1();

private slots:
    void on_connecter_clicked();

private:
    Ui::authen1 *ui;
};

#endif // AUTHEN1_H
