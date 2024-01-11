#include "comptevente.h"
#include "ui_comptevente.h"
#include "QMessageBox"
#include"QSqlQuery"
#include"modifierachat.h"
#include"QSqlQueryModel"

comptevente::comptevente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comptevente)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();
    QSqlQuery query;
    QString montant;

/*
    insert.exec("SELECT SUM(total) FROM vente");
    if(insert.next()){
       verif = insert.value(0).toString();
    }
    valeur=verif;
    requete.exec("INSERT INTO comptevente ( montant ) Values ('"+verif+"')");

*/
    int INT12=1;
   QString INT= QString::number(INT12);
    query.exec("SELECT montant FROM comptevente where id='"+INT+"'");

    if(query.exec()){
        if(query.next()){
        montant = query.value(0).toString();
        }
        ui->montant->setText(montant);
    }else{
        QMessageBox::critical(this,"message","erreur");
    }



}

comptevente::~comptevente()
{
    delete ui;
}
