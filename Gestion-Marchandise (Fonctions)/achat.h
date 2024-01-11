#ifndef ACHAT_H
#define ACHAT_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>
#include"QComboBox"
namespace Ui {
class achat;
}

class achat : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db;
    explicit achat(QWidget *parent = nullptr);
    ~achat();

private slots:
    void on_pushButton_clicked();

    void on_soumettre_clicked();

    void on_acheter_clicked();

private:
    Ui::achat *ui;
    QList<QSqlQuery> produit;
    QComboBox * combo=new QComboBox(this);

};

#endif // ACHAT_H
