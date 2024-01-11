#include "authen.h"
#include "ui_authen.h"
#include"utilisateur.h"
#include "QMessageBox"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
authen::authen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authen)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();
}

authen::~authen()
{
    delete ui;
}

void authen::on_connecter_clicked()
{

    db.open();


    QString Username = ui->username->text();
    QString Password = ui->password->text();

QSqlQuery recherche;
QString valeur,grade1="Administrateur";
recherche= QSqlQuery("select nomutilisateur from utilisateur where grade='"+grade1+"'");

if(recherche.next()){
     valeur= recherche.value(0).toString();
}
QSqlQuery recherche1;
QString valeur1;
recherche1= QSqlQuery("select motdepasse from utilisateur where grade='"+grade1+"'");

if(recherche1.next()){
     valeur1= recherche1.value(0).toString();
}

    if(valeur ==Username && valeur1 == Password)
    {
        QMessageBox::information(this,"albert", "log in succes");

    close();
    utilisateur * Utilisateur= new utilisateur;
    Utilisateur->show();
    }else{
        QMessageBox::critical(this,"echec", "identifiant inccorect");
        ui->username->clear();
        ui->password->clear();
    }

}

