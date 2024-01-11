#include "modifiermarchandise.h"
#include "ui_modifiermarchandise.h"
#include "QMessageBox"
#include"QSqlQuery"

modifiermarchandise::modifiermarchandise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifiermarchandise)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");


  db.open();
  QSqlQuery recherche ,select,selct2,update ;
  QString recherche2,val;
QList<QString> recherche1;
QList<QString> recherche3;

int INT=1;
  val=QString::number(INT);
select.exec("SELECT * from marchandise where cle='"+val+"'");

 while(select.next()){


     ui->idproduit->setText(select.value(0).toString());
     ui->nomproduit->setText(select.value(1).toString());
     ui->prix->setText(select.value(3).toString());
      ui->tca->setText(select.value(4).toString());
      ui->fournisseur->setText(select.value(5).toString());
       ui->categorie->setText(select.value(6).toString());
        ui->remarque->setText(select.value(8).toString());
         ui->quantite->setText(select.value(2).toString());
          ui->mois->setText(select.value(11).toString());
           ui->anne->setText(select.value(10).toString());
            ui->jour->setText(select.value(12).toString());

 }

 QString valeur2;
   int INT2=0;
   valeur2=QString::number(INT2);
    update.exec("UPDATE marchandise set cle='"+valeur2+"' where cle='"+val+"'");

}

modifiermarchandise::~modifiermarchandise()
{
    delete ui;
}

void modifiermarchandise::on_modifier_clicked()
{


}
void modifiermarchandise::on_annuler_clicked()
{

}



void modifiermarchandise::on_acheter_clicked()
{
    db.open();


    QString Idmarchandise = ui->idproduit->text();
    QSqlQuery id;
    QString verifier;
    id.exec("SELECT idproduit from marchandise where idproduit='"+Idmarchandise+"'");
    if(id.next()){
        verifier =id.value(0).toString();
    }
    if(verifier.isEmpty()){
        QMessageBox::critical(this, "Erreur", "ID achat introuvable");
        ui->idproduit->clear();
    }else{
        QString Nomproduit = ui->nomproduit ->toPlainText();
        QString Quantite =ui->quantite->text() ;
        QString Quantite1 =ui->quantite->text() + "unite";
        QString Prix =ui->prix->text() ;
        QString Prix1 =ui->prix->text() + "gourdes";
        QString TCA =ui->tca ->text() ;
        QString TCA1 =ui->tca ->text() + "gourdes";
        QString Fournisseur =ui->fournisseur->toPlainText();
        QString Categorie =ui->categorie ->text();

        QString Anne =ui->anne->text();
        QString mois=ui->mois->text();
        QString Jour=ui->jour->text();
        QString Date= Anne + "/" + mois +"/" + Jour;


         QString Remarque =ui->remarque->toPlainText();
         int Totale=Quantite.toInt() * Prix.toInt() + TCA.toInt();
         QString total=QString::number(Totale);
         QString total1=QString::number(Totale) + "Gourdes";


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
   QSqlQuery update;

   update.exec("UPDATE marchandise  SET nom= '"+Nomproduit+"', quantite='"+ Quantite+"', prix= '"+ Prix +"', tca='"+ TCA+"', fournisseur='"+ Fournisseur+"',Categorie='"+ Categorie+"', Date='"+ Date+"',remarque='"+ Remarque+"' , total='"+ total1+"', anne='"+Anne+"',mois='"+mois+"',jour='"+Jour+"'  WHERE idproduit='"+Idmarchandise+"'");
  if(update.exec()){

      QMessageBox::information(this,"Message", " Modifier avec succes");
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
}else{
       QMessageBox::information(this,"Message", " Modification echouer");
  }
}
}
}
}
    }
    close();

}


void modifiermarchandise::on_pushButton_clicked()
{
    QMessageBox ::StandardButton reply = QMessageBox::question(this , "caisse","Voulez vous vraiment l annuler ?" , QMessageBox::Yes | QMessageBox::No );
    if( reply ==QMessageBox::Yes){
        close();


    }
    else{}
}

