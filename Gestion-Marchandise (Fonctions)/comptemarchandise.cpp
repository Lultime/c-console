#include "comptemarchandise.h"
#include "ui_comptemarchandise.h"
#include "QMessageBox"
#include"QSqlQuery"
#include"modifierachat.h"
#include"QSqlQueryModel"

comptemarchandise::comptemarchandise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comptemarchandise)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();
    QSqlQuery query;

   QString montant="";
    query.exec("SELECT SUM(total) FROM marchandise");
    while(query.next()){
    montant += query.value(0).toString() + "  Gourdes";
    }

 ui->montant->setText(montant);



}

comptemarchandise::~comptemarchandise()
{
    delete ui;
}
