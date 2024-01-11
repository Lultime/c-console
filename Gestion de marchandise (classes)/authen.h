#ifndef AUTHEN_H
#define AUTHEN_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>
namespace Ui {
class authen;
}

class authen : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit authen(QWidget *parent = nullptr);
    ~authen();

private slots:
    void on_connecter_clicked();

private:
    Ui::authen *ui;
};

#endif // AUTHEN_H
