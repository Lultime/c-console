#include "actif.h"
#include "ui_actif.h"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"

actif::actif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::actif)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

   db.open();
   QSqlQuery select,select2,select3;
   QString select1,montant,select4,select5;
   int INT12=1;
  QString INT= QString::number(INT12);
   select.exec("SELECT montant FROM comptevente where id='"+INT+"'");
   while(select.next()){
       select1=select.value(0).toString();
   }

   select2.exec("SELECT SUM(total) from marchandise");
   while(select2.next()){
       select4=select2.value(0).toString();
   }


   select3.exec("SELECT SUM(quantite) from depense");
   while(select3.next()){
       select5=select3.value(0).toString();
   }

   int montan2=select1.toInt() + select4.toInt() ;
   montant=QString::number(montan2);
   ui->montant->setText(montant);
}

actif::~actif()
{
    delete ui;
}
