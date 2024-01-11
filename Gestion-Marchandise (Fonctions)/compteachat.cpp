#include "compteachat.h"
#include "ui_compteachat.h"
#include "QMessageBox"
#include"QSqlQuery"
#include"modifierachat.h"
#include"QSqlQueryModel"

compteachat::compteachat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compteachat)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();
    QSqlQuery query;

   QString montant="";
   int INT12=2;
  QString INT= QString::number(INT12);
   query.exec("SELECT SUM(total) FROM achat");

    while(query.next()){
    montant += query.value(0).toString() + "  Gourdes";
    }

 ui->montant->setText(montant);




}

compteachat::~compteachat()
{
    delete ui;
}
