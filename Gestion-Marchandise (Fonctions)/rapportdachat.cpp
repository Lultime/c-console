#include "rapportdachat.h"
#include "ui_rapportdachat.h"
#include"QMessageBox"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include"accueil.h"
#include "QSqlQuery"
#include"QSqlQueryModel"

rapportdachat::rapportdachat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rapportdachat)
{
    ui->setupUi(this);

    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();
    int Int=1;
    QString Int1=QString::number(Int);
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT nom,prix,quantite,total from achat where cle='"+Int1+"'");
    QSqlQuery somme,Delete,Date;
    QString montant,Date2;

somme.exec("SELECT SUM(total) from achat where cle='"+Int1+"'");
Date.exec("SELECT Date from achat where cle='"+Int1+"'");
if(Date.next()){
    Date2=Date.value(0).toString();
}
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}

 ui->montant->setText(montant);
ui->Date->setText(Date2);
 QSqlQueryModel * modal =new QSqlQueryModel();

 modal->setQuery(query);

 ui->tableView->setModel(modal);
 int Int0=0;
 QString Int2=QString::number(Int0);
Delete.exec("UPDATE achat set cle='"+Int2+"' where cle='"+Int1+"'");
query.clear();
db.close();
}

rapportdachat::~rapportdachat()
{
    delete ui;
}

void rapportdachat::on_save_clicked()
{

}


void rapportdachat::on_print_clicked()
{

}

