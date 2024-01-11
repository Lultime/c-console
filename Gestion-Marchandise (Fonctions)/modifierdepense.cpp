#include "modifierdepense.h"
#include "ui_modifierdepense.h"
#include"QSqlQuery"
#include"QMessageBox"
modifierdepense::modifierdepense(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierdepense)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

  db.open();
}

modifierdepense::~modifierdepense()
{
    delete ui;
}

void modifierdepense::on_modifier_clicked()
{

        db.open();


        QString Iddepense = ui->iddepense->text();
        QSqlQuery id;
        QString verifier;
        id.exec("SELECT iddepense from depense where iddepense='"+Iddepense+"'");
        if(id.next()){
            verifier =id.value(0).toString();
        }
        if(verifier.isEmpty()){
            QMessageBox::critical(this, "Erreur", "ID achat introuvable");
            ui->iddepense->clear();
        }else{

            QString motif = ui->motif->toPlainText();
            QString quantite =ui->quantite ->text() + "Gourdes";
            QString Compte =ui->Compte->text();
            QString Anne =ui->anne->text();
            QString mois=ui->mois->text();
            QString Jour=ui->jour->text();
            QString Date= Anne + "/" + mois +"/" + Jour;



        if(motif.isEmpty() || quantite.isEmpty() || Compte.isEmpty()){

           QMessageBox::critical(this,"Message", "Veuiller remplir tous les champs");
        }else{
            if(!quantite.toInt() && motif.toInt() || Compte.toInt()){
                QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");

            }else{
                if(!Anne.toInt() || !mois.toInt() || !Jour.toInt()){
                    QMessageBox::critical(this, "message","Format date incorrect ");


                }else{
                    if(Anne.length() < 4 || Anne.length() == 3 || Anne.length() == 2 || Anne.length() == 1 || Anne.length() == 0 || mois.length() < 2 || mois.length() == 0 ||mois.length() == 1 || Jour.length() < 2 ||Jour.length() == 0 ||Jour.length() == 1){
                        QMessageBox::critical(this, "message","Format date incorrect ");

                    }else{
            QSqlQuery query,update;
            query = QSqlQuery("SELECT SUM(total)  FROM vente ");
             if(query.exec()){

             int reste=0;
             int RReste;
             QString Reste;
             if(query.next()){
                reste=query.value(0).toInt();
                if(reste < quantite.toInt()){
                    QMessageBox::critical(this,"Message", "Quantite  requis non disponible");

                }else{
               RReste=reste - quantite.toInt() ;
               Reste= QString::number(RReste);
               update.exec("UPDATE vente SET SUM(total)='"+Reste+"'");
           }
             }

     QSqlQuery update1;

     update1.exec("UPDATE depense SET motif= '"+ motif +"', quantite= '"+ quantite+"' , compte= '"+ Compte +"', date= '"+ Date+"' , anne='"+Anne+"',mois='"+mois+"',jour='"+Jour+"'   WHERE iddepense='"+Iddepense+"'");

        QMessageBox::information(this,"Message", " Modifier avec succes");

        ui->motif->clear();
        ui->quantite->clear();
        ui->anne ->clear();
        ui->mois->clear();
        ui->jour->clear();
       ui->Compte->clear();


   db.close();
      close();
}

}
}
}
}
        }
}
void modifierdepense::on_annuler_clicked()
{
    QMessageBox ::StandardButton reply = QMessageBox::question(this , "caisse","Voulez vous vraiment l annuler ?" , QMessageBox::Yes | QMessageBox::No );
    if( reply ==QMessageBox::Yes){
        close();


    }
    else{}
}

