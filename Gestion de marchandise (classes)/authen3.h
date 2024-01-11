#ifndef AUTHEN3_H
#define AUTHEN3_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class authen3;
}

class authen3 : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit authen3(QWidget *parent = nullptr);
    ~authen3();

private slots:
    void on_connecter_clicked();

private:
    Ui::authen3 *ui;
};

#endif // AUTHEN3_H
