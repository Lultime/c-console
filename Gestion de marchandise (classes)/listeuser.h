#ifndef LISTEUSER_H
#define LISTEUSER_H

#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>
namespace Ui {
class listeuser;
}

class listeuser : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit listeuser(QWidget *parent = nullptr);
    ~listeuser();

private slots:
    void on_suprimer_2_clicked();

    void on_pushButton_clicked();

    void on_suprimer_clicked();

private:
    Ui::listeuser *ui;
};

#endif // LISTEUSER_H
