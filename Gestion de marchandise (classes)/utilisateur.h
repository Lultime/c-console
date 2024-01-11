#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include"string"
namespace Ui {
class utilisateur;
 extern QString email;
}

class utilisateur : public QDialog
{
    Q_OBJECT


public:

    QSqlDatabase db;
    explicit utilisateur(QWidget *parent = nullptr);
    ~utilisateur();

private slots:
    void on_pushButton_clicked();

    void on_enregistrer_clicked();

private:
    Ui::utilisateur *ui;
};

#endif // UTILISATEUR_H
