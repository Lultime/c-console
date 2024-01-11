#include "marchandise.h"
#include "ui_marchandise.h"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "accueil.h"

marchandise::marchandise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::marchandise)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

  db.open();
}

marchandise::~marchandise()
{
    delete ui;
}

void marchandise::on_soumettre_clicked()
{
    db.open();
       QSqlQuery requeteInsert;
       QString Nomproduit = ui->nomproduit ->toPlainText();
       QString Quantite =ui->quantite->text() ;
       QString Quantite1 =ui->quantite->text() + " unite";
       QString Prix =ui->prix->text() ;
       QString Prix1 =ui->prix->text() + " gourdes";
       QString TCA =ui->tca ->text() ;
       QString TCA1 =ui->tca ->text() + " gourdes";
       QString Fournisseur =ui->fournisseur->toPlainText();
       QString Categorie =ui->categorie ->text();

       QString Anne =ui->anne->text();
       QString mois=ui->mois->text();
       QString Jour=ui->jour->text();
       QString Date= Anne + "/" + mois +"/" + Jour;


        QString Remarque =ui->remarque->toPlainText();
        int Totale=Quantite.toInt() * Prix.toInt() + TCA.toInt();
        QString total=QString::number(Totale);
        QString total1=QString::number(Totale) + " gourdes";


       if(Nomproduit.isEmpty() || Quantite.isEmpty() || Prix.isEmpty() || TCA.isEmpty() || Fournisseur.isEmpty() || Categorie.isEmpty()){

           QMessageBox::critical(this,"Message", "Veuiller remplir tous les champs");
       }else{

           if(!Quantite.toInt() || !Prix.toInt() || !TCA.toInt() && Nomproduit.toInt() || Fournisseur.toInt() || Categorie.toInt() ){
               QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");

           }else{
               if(!Anne.toInt() || !mois.toInt() || !Jour.toInt()){
                   QMessageBox::critical(this, "message","Format date incorrect ");


               }else{
                   if(Anne.length() < 4 || Anne.length() == 3 || Anne.length() == 2 || Anne.length() == 1 || Anne.length() == 0 || mois.length() < 2 || mois.length() == 0 ||mois.length() == 1 || Jour.length() < 2 ||Jour.length() == 0 ||Jour.length() == 1){
                       QMessageBox::critical(this, "message","Format date incorrect ");

                   }else{
      QSqlQuery insert2;



  insert2 = QSqlQuery("INSERT INTO marchandise (nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total, anne,mois,jour) values('"+Nomproduit+"','"+ Quantite+"','"+ Prix+"','"+ TCA+"','"+ Fournisseur+"','"+ Categorie+"','"+ Date+"','"+ Remarque+"','"+ total+"','"+ Anne+"','"+ mois+"','"+ Jour+"')");


       QMessageBox::information(this,"Message", "votre enregistrement a ete enregistrer avec succes");
     ui->nomproduit ->clear();
      ui->quantite ->clear();
       ui->prix->clear();
       ui->tca ->clear();
       ui->fournisseur->clear();
       ui->categorie ->clear();
       ui->anne ->clear();
       ui->mois->clear();
       ui->jour->clear();
       ui->remarque->clear();
}
}
}
       }
}
void marchandise::on_pushButton_clicked()
{
    QMessageBox ::StandardButton reply = QMessageBox::question(this , "achat","Voulez vous vraiment l annuler ?" , QMessageBox::Yes | QMessageBox::No );
    if( reply ==QMessageBox::Yes){
        close();

    }
    else{}
}

