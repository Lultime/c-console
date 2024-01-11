#ifndef CONNEXION_H
#define CONNEXION_H
#define DEPENSE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"

#include <QMessageBox>

namespace Ui {
class connexion;
}

class connexion : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db;
    explicit connexion(QWidget *parent = nullptr);
    ~connexion();

private slots:


    void on_connecter_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::connexion *ui;
};

#endif // CONNEXION_H
