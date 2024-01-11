#include "listeuser.h"
#include "ui_listeuser.h"
#include"QSqlQueryModel"
#include "QMessageBox"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "accueil.h"

listeuser::listeuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listeuser)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();
    QSqlQuery usere;
    QString verifiere;
    usere.exec("SELECT idutilisateur, nom , prenom , email ,  grade FROM utilisateur");
    if(usere.next()){
     verifiere= usere.value(0).toString();
    }

        QSqlQueryModel * modal =new QSqlQueryModel();

        modal->setQuery(usere);

        ui->tableView->setModel(modal);
       usere.clear();

}

listeuser::~listeuser()
{
    delete ui;
}

void listeuser::on_suprimer_2_clicked()
{
  close();

}

void listeuser::on_suprimer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}


void listeuser::on_pushButton_clicked()
{
    db.open();
    QString Idutilisateur=ui->lineEdit->text();
    QSqlQuery sup;
    QString sup2;
    sup.exec("DELETE FROM utilisateur where idutilisateur="+Idutilisateur);
    QMessageBox::information(this,"Message", " Supprimer avec succes");
    ui->lineEdit->clear();
    QSqlQuery usere;
    QString verifiere;
    usere.exec("SELECT idutilisateur, nom , prenom , email ,  grade FROM utilisateur");
    if(usere.next()){
     verifiere= usere.value(0).toString();
    }

        QSqlQueryModel * modal =new QSqlQueryModel();

        modal->setQuery(usere);

        ui->tableView->setModel(modal);
       usere.clear();

}




