#include "redigerrapportdepense.h"
#include "ui_redigerrapportdepense.h"
#include"QMessageBox"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include"accueil.h"
#include "QSqlQuery"
#include"QSqlQueryModel"
#include"rapportdepense.h"
redigerrapportdepense::redigerrapportdepense(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::redigerrapportdepense)
{
    ui->setupUi(this);

    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

  db.open();
}

redigerrapportdepense::~redigerrapportdepense()
{
    delete ui;
}

void redigerrapportdepense::on_autredepense_clicked()
{
    db.open();



     QString motif = ui->motif->toPlainText();
     QString quantite =ui->quantite ->text();
     QString quantite1 =ui->quantite ->text() + " Gourdes";
     QString Compte =ui->Compte->text();
     QString Anne =ui->anne->text();
     QString mois=ui->mois->text();
     QString Jour=ui->jour->text();
     QString Date= Anne + "/" + mois +"/" + Jour;

  int reste=0;
  QSqlQuery query,update,query2,update2;





     if(motif.isEmpty() || quantite.isEmpty()  || Compte.isEmpty()){

         QMessageBox::critical(this,"Message", "Veuiller remplir tous les champs");
     }else{
         if(!quantite.toInt() || motif.toInt() || Compte.toInt()){
             QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");

         }else{


             /*
             QString test;
            query2.exec("SELECT idvente from vente where idvente='"+Compte+"'");
            if(query2.next()){
                test = query2.value(0).toString();
            }
            if(test.isEmpty()){
                QMessageBox::critical(this,"Message", " erreur d'id");
                ui->compte->clear();
            }else{
            */
             query = QSqlQuery("SELECT montant FROM comptevente");

             int RReste;
             QString Reste,restes;
             if(query.next()){
                reste=query.value(0).toInt();

                if(reste < quantite.toInt()){
                    QMessageBox::critical(this,"Message", "Quantite  requis non disponible");
                    ui->quantite->clear();

                }else{
                     /*
                    if(ui->Compte->text() != "vente" || ui->Compte->text() !="Vente"){
                        QMessageBox::critical(this,"Message", "Depense pouvant etre effectue dans compte vente uniquement ");
                        ui->Compte->clear();

                    }else{
                    */
                        if(!Anne.toInt() || !mois.toInt() || !Jour.toInt()){
                            QMessageBox::critical(this, "message","Format date incorrect ");


                        }else{
                            if(Anne.length() < 4 || Anne.length() == 3 || Anne.length() == 2 || Anne.length() == 1 || Anne.length() == 0 || mois.length() < 2 || mois.length() == 0 ||mois.length() == 1 || Jour.length() < 2 ||Jour.length() == 0 ||Jour.length() == 1){
                                QMessageBox::critical(this, "message","Format date incorrect ");

                            }else{

               RReste=reste - quantite.toInt() ;
               Reste= QString::number(RReste) + "Gourdes";

            update.exec("UPDATE vente SET somme='"+Reste+"'");
              update2.exec("UPDATE comptevente SET montant='"+Reste+"'");

     QSqlQuery insert;
     int Int=1;
     QString Int1=QString::number(Int);

  insert = QSqlQuery("INSERT INTO depense (motif, quantite,Date,compte,anne,mois,jour,cle) values('"+motif+"','"+quantite+"','"+Date+"','"+Compte+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");






     QMessageBox::information(this,"Message", " votre depense a ete effectue  avec succes");

     ui->motif->clear();
     ui->quantite->clear();
     ui->anne ->clear();
     ui->mois->clear();
     ui->jour->clear();
     ui->Compte->clear();

 db.close();

 }
 }
 }
 }

     }
 }
}


void redigerrapportdepense::on_annuler_clicked()
{

}


void redigerrapportdepense::on_termine_clicked()
{
    db.open();



     QString motif = ui->motif->toPlainText();
     QString quantite =ui->quantite ->text();
     QString quantite1 =ui->quantite ->text() + " Gourdes";
     QString Compte =ui->Compte->text();
     QString Anne =ui->anne->text();
     QString mois=ui->mois->text();
     QString Jour=ui->jour->text();
     QString Date= Anne + "/" + mois +"/" + Jour;

  int reste=0;
  QSqlQuery query,update,query2,update2;





     if(motif.isEmpty() || quantite.isEmpty()  || Compte.isEmpty()){

         QMessageBox::critical(this,"Message", "Veuiller remplir tous les champs");
     }else{
         if(!quantite.toInt() || motif.toInt() || Compte.toInt()){
             QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");

         }else{


             /*
             QString test;
            query2.exec("SELECT idvente from vente where idvente='"+Compte+"'");
            if(query2.next()){
                test = query2.value(0).toString();
            }
            if(test.isEmpty()){
                QMessageBox::critical(this,"Message", " erreur d'id");
                ui->compte->clear();
            }else{
            */
             query = QSqlQuery("SELECT montant FROM comptevente");

             int RReste;
             QString Reste,restes;
             if(query.next()){
                reste=query.value(0).toInt();

                if(reste < quantite.toInt()){
                    QMessageBox::critical(this,"Message", "Quantite  requis non disponible");
                    ui->quantite->clear();

                }else{
                     /*
                    if(ui->Compte->text() != "vente" || ui->Compte->text() !="Vente"){
                        QMessageBox::critical(this,"Message", "Depense pouvant etre effectue dans compte vente uniquement ");
                        ui->Compte->clear();

                    }else{
                    */
                        if(!Anne.toInt() || !mois.toInt() || !Jour.toInt()){
                            QMessageBox::critical(this, "message","Format date incorrect ");


                        }else{
                            if(Anne.length() < 4 || Anne.length() == 3 || Anne.length() == 2 || Anne.length() == 1 || Anne.length() == 0 || mois.length() < 2 || mois.length() == 0 ||mois.length() == 1 || Jour.length() < 2 ||Jour.length() == 0 ||Jour.length() == 1){
                                QMessageBox::critical(this, "message","Format date incorrect ");

                            }else{

               RReste=reste - quantite.toInt() ;
               Reste= QString::number(RReste) + "Gourdes";

            update.exec("UPDATE vente SET somme='"+Reste+"'");
              update2.exec("UPDATE comptevente SET montant='"+Reste+"'");

     QSqlQuery insert;
     int Int=1;
     QString Int1=QString::number(Int);

  insert = QSqlQuery("INSERT INTO depense (motif, quantite,Date,compte,anne,mois,jour,cle) values('"+motif+"','"+quantite+"','"+Date+"','"+Compte+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");




     QMessageBox::information(this,"Message", " votre depense a ete effectue  avec succes");

     ui->motif->clear();
     ui->quantite->clear();
     ui->anne ->clear();
     ui->mois->clear();
     ui->jour->clear();
     ui->Compte->clear();

 db.close();
 rapportdepense * Rapportdepense=new rapportdepense();
 Rapportdepense->show();

 }
 }
 }
 }

     }
 }
}

