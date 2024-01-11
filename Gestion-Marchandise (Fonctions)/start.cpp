#include "start.h"
#include "ui_start.h"
#include"QSqlQuery"
#include"QMessageBox"
#include"connexion.h"
#include"accueil.h"

start::start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::start)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

        db.open();
    QSqlQuery user;
    QString verifier;
    user.exec("SELECT * FROM utilisateur");
    if(user.exec()){
    if(user.next()){
        verifier =user.value(0).toString();
    }
    if(!verifier.isEmpty()){
         connexion * Connexion= new connexion;
         Connexion->show();

           }else{
        accueil * Accueil=new accueil;
        Accueil->show();

    }
    db.close();
    }else{
    QMessageBox::critical(this,"erreur open","erreur open");
}
    close();
}



start::~start()
{
    delete ui;

}

