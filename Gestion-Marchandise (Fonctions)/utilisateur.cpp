#include "utilisateur.h"
#include "ui_utilisateur.h"
#include "QMessageBox"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "accueil.h"

utilisateur::utilisateur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::utilisateur)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
   db.open();


     QString email=ui->email->text();


}

utilisateur::~utilisateur()
{
    delete ui;
}

void utilisateur::on_pushButton_clicked()
{
    QMessageBox ::StandardButton reply = QMessageBox::question(this , "utilisateur","Voulez vous vraiment l annuler ?" , QMessageBox::Yes | QMessageBox::No );
    if( reply ==QMessageBox::Yes){
        close();

    }
    else{}
}


void utilisateur::on_enregistrer_clicked()
{ 
    db.open();

    QString Nom = ui->nom ->text();
    QString Prenom =ui->prenom ->text();
    QString Nomutilisateur =ui->nomutilisateur->text();
    QString Email=ui->email->text();
     QString Sexe = ui->sexe->currentText();
    QString Datenaissance =ui->datenaissance->text();
       QString password =ui->motdepasse ->text();
    QString confirmpassword = ui->motdepasseconfirm->text();

    if(Nom.isEmpty() || Prenom.isEmpty() || Nomutilisateur.isEmpty() || Datenaissance.isEmpty() || password.isEmpty() || confirmpassword.isEmpty()){

        QMessageBox::critical(this,"Message", "Veuiller remplir tous les champs");
    }else{

        if(password != confirmpassword){
            QMessageBox::critical(this,"Message", "les mots de passe ne corespondent pas");
            ui->motdepasse->clear();
            ui->motdepasseconfirm->clear();

        }else{
            QSqlQuery user;
            QString verifier;
            user.exec("SELECT * FROM utilisateur");

            if(user.next()){
                verifier =user.value(0).toString();
            }
            if(verifier.isEmpty()){
   QSqlQuery insert1;
  QString adm="Administrateur";
insert1.exec("INSERT into utilisateur (nom, prenom, nomutilisateur , email, datenaissance, sexe,motdepasse, motdepasseconfirm,grade) values('"+Nom+"','"+Prenom+"','"+Nomutilisateur+"','"+Email+"','"+Datenaissance+"','"+ Sexe+"','"+password+"', '"+confirmpassword+"','"+adm+"')");

if(insert1.exec()){

    QMessageBox::information(this,"Message", "Enregistrer avec succes");
    ui->nom->clear();
    ui->prenom->clear();
    ui->nomutilisateur->clear();
    ui->datenaissance->clear();
    ui->sexe->clear();
    ui->motdepasse->clear();
    ui->motdepasseconfirm->clear();
}else{
    QMessageBox::critical(this, "erreur" , "Erreur");
    ui->nom->clear();
    ui->prenom->clear();
    ui->nomutilisateur->clear();
    ui->datenaissance->clear();
    ui->sexe->clear();
    ui->motdepasse->clear();
    ui->motdepasseconfirm->clear();
}
            }else{
                QString grade="User";
                  QSqlQuery insert1;
                insert1.exec("INSERT into utilisateur (nom, prenom, nomutilisateur , email, datenaissance, sexe,motdepasse, motdepasseconfirm,grade) values('"+Nom+"','"+Prenom+"','"+Nomutilisateur+"','"+Email+"','"+Datenaissance+"','"+ Sexe+"','"+password+"', '"+confirmpassword+"','"+grade+"')");

                if(insert1.exec()){

                    QMessageBox::information(this,"Message", "Enregistrer avec succes");
                    ui->nom->clear();
                    ui->prenom->clear();
                    ui->nomutilisateur->clear();
                    ui->datenaissance->clear();
                    ui->sexe->clear();
                    ui->motdepasse->clear();
                    ui->motdepasseconfirm->clear();
                }else{
                    QMessageBox::critical(this, "erreur" , "Erreur");
                    ui->nom->clear();
                    ui->prenom->clear();
                    ui->nomutilisateur->clear();
                    ui->datenaissance->clear();
                    ui->sexe->clear();
                    ui->motdepasse->clear();
                    ui->motdepasseconfirm->clear();
                }
            }
    db.close();
}
}
}
