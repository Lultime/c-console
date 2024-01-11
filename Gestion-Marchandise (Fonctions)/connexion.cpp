#include "connexion.h"
#include "ui_connexion.h"
#include "ui_utilisateur.h"
#include"utilisateur.h"
#include "accueil.h"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include"authen.h"
connexion::connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connexion)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();



}

connexion::~connexion()
{
    delete ui;
}

void connexion::on_connecter_clicked()
{
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

    QString Username = ui->username->text();
    QString Password = ui->password->text();

QSqlQuery recherche;
QString valeur;
recherche= QSqlQuery("select nomutilisateur from utilisateur where nomutilisateur='"+Username+"'");

if(recherche.next()){
     valeur= recherche.value(0).toString();
}
QSqlQuery recherche1;
QString valeur1;
recherche1= QSqlQuery("select motdepasse from utilisateur where motdepasse='"+Password+"'");

if(recherche1.next()){
     valeur1= recherche1.value(0).toString();
}

    if(!valeur.isEmpty() && !valeur1.isEmpty())
    {
        QSqlQuery insert;
        QMessageBox::information(this,"albert", "log in succes");
        this->show();
        QString Username= ui->username->text();
        QString Password= ui->password->text();
        int Int=1;
        QString Int1=QString::number(Int);
  insert.exec("update utilisateur set  cle='"+Int1+"' where nomutilisateur='"+Username+"'");
    accueil * Accueil = new accueil ();
    Accueil->show();
    close();
    }else{
        QMessageBox::critical(this,"echec", "identifiant inccorect");
        ui->username->clear();
        ui->password->clear();
    }

   // close();
}





void connexion::on_pushButton_2_clicked()
{

    authen * Authen= new authen;
    Authen->show();
}

