#include "benefice.h"
#include "ui_benefice.h"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

benefice::benefice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::benefice)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

   db.open();
   QSqlQuery select;
   QString select1,montant;
   QString titre="Benefice total realise sur vente";
   ui->label_4->setText(titre);
   select.exec("SELECT SUM(benefice) from vente");

   while(select.next()){
       select1=select.value(0).toString();
   }

    ui->montant->setText(select1);
}

benefice::~benefice()
{
    delete ui;
}

void benefice::on_mois_2_clicked()
{
    db.open();
   QString mois=ui->mois->text();
   QString titre="Benefice sur vente realise le " + mois +"eme mois";
   ui->label_4->setText(titre);
   QSqlQuery select;
   QString select1,montant;

   select.exec("SELECT SUM(benefice) from vente where mois='"+mois+"'");

   while(select.next()){
       select1=select.value(0).toString();
   }

    ui->montant->setText(select1);
    ui->mois->clear();

}


void benefice::on_jour_2_clicked()
{
    db.open();
   QString Jour=ui->jour->text();
   QString titre="Benefice sur vente realise le " + Jour;
   ui->label_4->setText(titre);
   QSqlQuery select;
   QString select1,montant;

   select.exec("SELECT SUM(benefice) from vente where jour='"+Jour+"'");

   while(select.next()){
       select1=select.value(0).toString();
   }

    ui->montant->setText(select1);
    ui->jour->clear();
}


void benefice::on_anne_2_clicked()
{
    db.open();
   QString Anne=ui->anne->text();
   QString titre="Benefice sur vente realise en " + Anne;
   ui->label_4->setText(titre);
   QSqlQuery select;
   QString select1,montant;

   select.exec("SELECT SUM(benefice) from vente where anne='"+Anne+"'");

   while(select.next()){
       select1=select.value(0).toString();
   }

    ui->montant->setText(select1);
    ui->mois->clear();
}


void benefice::on_tout_2_clicked()
{
    db.open();
    QSqlQuery select;
    QString select1,montant;
    QString titre="Benefice total realise sur vente";
    ui->label_4->setText(titre);
    select.exec("SELECT SUM(benefice) from vente");

    while(select.next()){
        select1=select.value(0).toString();
    }

     ui->montant->setText(select1);
}

