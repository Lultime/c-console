#include "modifierachat.h"
#include "ui_modifierachat.h"
#include "QMessageBox"
#include"QSqlQuery"

modifierachat::modifierachat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierachat)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

  db.open();
}

modifierachat::~modifierachat()
{
    delete ui;
}

void modifierachat::on_modifier_clicked()
{

    db.open();


    QString Idachat = ui->idachat->text();
QSqlQuery id;
QString verifier;
id.exec("SELECT idproduit from achat where idproduit='"+Idachat+"'");
if(id.next()){
    verifier =id.value(0).toString();
}
if(verifier.isEmpty()){
    QMessageBox::critical(this, "Erreur", "ID achat introuvable");
    ui->idachat->clear();
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

   update.prepare("update achat set nom='"+Nomproduit+"', quantite='"+Quantite+"', prix= '"+Prix+"', tca='"+TCA+"', fournisseur='"+Fournisseur+"',Categorie='"+Categorie+"', Date='"+Date+"',remarque='"+Remarque+"' ,total='"+total1+"' , anne='"+Anne+"',mois='"+mois+"',jour='"+Jour+"' where idproduit ='"+Idachat+"'");
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
       QMessageBox::critical(this,"Message", " erreur");
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
   db.close();




}

}
}
     }
}
}
void modifierachat::on_annuler_clicked()
{
    QMessageBox ::StandardButton reply = QMessageBox::question(this , "caisse","Voulez vous vraiment l annuler ?" , QMessageBox::Yes | QMessageBox::No );
    if( reply ==QMessageBox::Yes){
        close();


    }
    else{}
}

