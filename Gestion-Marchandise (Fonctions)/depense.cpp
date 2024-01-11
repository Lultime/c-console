#include "depense.h"
#include "ui_depense.h"
#include"QMessageBox"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include"accueil.h"
#include "QSqlQuery"

depense::depense(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depense)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/eglise.sqlite/eglise.sqlite");

}

depense::~depense()
{
    delete ui;
}

void depense::on_pushButton_3_clicked()
{
    QMessageBox ::StandardButton reply = QMessageBox::question(this , "Depense","Voulez vous vraiment l annuler ?" , QMessageBox::Yes | QMessageBox::No );
    if( reply ==QMessageBox::Yes){

        close();

    }
    else{}
}


void depense::on_pushButton_clicked()
{
    //connexion base de donnee

   db.open();

    QString idcaisse =ui->idcaisse->text();
    QString idevenement= ui->idevenement->text();
    QString motif = ui->motif->text();
    QString quantite =ui->quantite ->text();
    QString date = ui->date->text();


    QSqlQuery insert;

 insert = QSqlQuery("INSERT INTO depense (idcaisse, idevenement, motif, quantite,date) values('"+idcaisse+"','"+idevenement+"','"+motif+"','"+quantite+"','"+date+"')");




    QMessageBox::information(this,"Message", " Enregistrer avec succes");
    ui->idcaisse->clear();
    ui->idevenement->clear();
    ui->motif->clear();
    ui->quantite->clear();
    ui->date->clear();

db.close();

}

