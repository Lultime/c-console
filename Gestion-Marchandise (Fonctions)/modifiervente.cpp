#include "modifiervente.h"
#include "ui_modifiervente.h"
#include"QSqlQuery"
#include"QMessageBox"
modifiervente::modifiervente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifiervente)
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
  select.exec("SELECT * from vente where cle='"+val+"'");

   while(select.next()){

       combo->addItem(select.value(1).toString());
       ui->idvente->setText(select.value(0).toString());
       ui->prixventesortie->setText(select.value(2).toString());
        ui->prixventevariation->setText(select.value(3).toString());
         ui->categorie->setText(select.value(4).toString());
          ui->remarque->setText(select.value(5).toString());
           ui->quantite->setText(select.value(6).toString());
            ui->mois->setText(select.value(11).toString());
             ui->anne->setText(select.value(10).toString());
              ui->jour->setText(select.value(12).toString());

   }

   QString valeur2;
     int INT2=0;
     valeur2=QString::number(INT2);
      update.exec("UPDATE vente set cle='"+valeur2+"' where cle='"+val+"'");


    recherche.exec("SELECT nom, idproduit from marchandise ");
    while(recherche.next()){
        recherche1 += /*recherche.value(0).toString() + "-" +*/ recherche.value(1).toString();
       recherche3  += recherche.value(0).toString();

    }


    setWindowTitle("Vente");

  combo->setGeometry(30,132,180,20);
    combo2->setGeometry(260,132,180,20);
    combo->addItem("");
  //  combo2->addItem("");

  combo->addItems(recherche3);

 //combo2->addItems(recherche1);

// combo2->addItem(recherche2);

 //ui->idproduit->setText(recherche);

}

modifiervente::~modifiervente()
{
    delete ui;
}

void modifiervente::on_modifier_clicked()
{
    db.open();


    Nomproduit = combo->currentText();
    QString Quantite =ui->quantite ->text() ;
    QString Quantite1 =ui->quantite ->text() + " unite";
    QString Prix_vente_sortie =ui->prixventesortie->text() ;
    QString prix_vente_variation=ui->prixventevariation ->text() ;
    QString Prix_vente_sortie1 =ui->prixventesortie->text() + " Gourdes";
    QString prix_vente_variation1=ui->prixventevariation ->text() + " Gourdes";
    QString Categorie =ui->categorie ->toPlainText();
    QString Anne =ui->anne->text();
    QString mois=ui->mois->text();
    QString Jour=ui->jour->text();
    QString Date= Anne + "/" + mois +"/" + Jour;
     QString Remarque =ui->remarque->toPlainText();
     QString Somme2;

     QString Idproduit=combo2->currentText();
     int Totale=Quantite.toInt() * prix_vente_variation.toInt() ;
     QString totale = QString::number(Totale) ;
     QString totale1 = QString::number(Totale) + " Gourdes";
     QString text="Albert";


     if(Nomproduit.isEmpty() || Quantite.isEmpty() || Prix_vente_sortie.isEmpty() || prix_vente_variation.isEmpty() || Categorie.isEmpty()){

         QMessageBox::critical(this,"Message", "Veuiller remplir tous les champs");
     }else{
         if(!Quantite.toInt() || !Prix_vente_sortie.toInt() || !prix_vente_variation.toInt()  || Categorie.toInt() ){
             QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");

         }else{

       QSqlQuery select,select1,query,select2;
         QString affichage="",affichage2,affichage3="",affichage4;
         int affichage1;

          query = QSqlQuery("SELECT montant FROM comptevente");
          QString Reste,reste;
          if(query.next()){
             reste=query.value(0).toString() ;

       }
           affichage1 = reste.toInt() + Totale;
       affichage3 =  QString::number(affichage1) ;


       /*
         select= QSqlQuery("SELECT nom FROM marchandise WHERE nom =\""+Nomproduit+"\" ");
         if(select.next()){
             affichage = select.value(0).toString();
          //   affichage += select.value(1).toString() ;

         }
         select1= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit+"\" and idproduit='"+Idproduit+"'");

         if(select1.next()){
             affichage2 = select1.value(0).toString() ;
         }


             if( affichage2 !=Idproduit){
                 QMessageBox::critical(this,"Message", "Ce produit n existe pas ou l'id ne correspond pas a ce produit(cle)");

                 combo->clear();
               combo2->clear();


         }else{
    */
             if(!Anne.toInt() || !mois.toInt() || !Jour.toInt()){
                 QMessageBox::critical(this, "message","Format date incorrect ");


             }else{
                 if(Anne.length() < 4 || Anne.length() == 3 || Anne.length() == 2 || Anne.length() == 1 || Anne.length() == 0 || mois.length() < 2 || mois.length() == 0 ||mois.length() == 1 || Jour.length() < 2 ||Jour.length() == 0 ||Jour.length() == 1){
                     QMessageBox::critical(this, "message","Format date incorrect ");

                 }else{
       QSqlQuery insert,update,update2,query,prix1,tca1;



     query = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom ='"+Nomproduit+"' and idproduit='"+Idproduit+"'");
      if(query.exec()){

      int reste=0;
      int RReste;
      QString Reste,prix,tca;
      if(query.next()){
         reste=query.value(0).toInt();
         if(reste < Quantite.toInt()){
             QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit+"' requis non disponible");

         }else{
             insert = QSqlQuery("INSERT INTO vente ( nom, quantite, Prix, prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour) values('"+Nomproduit+"','"+Quantite1+"','"+Prix_vente_sortie1+"','"+prix_vente_variation1+"','"+Categorie+"','"+Date+"','"+Remarque+"','"+totale1+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"')");
             update2.exec("UPDATE comptevente SET   montant='"+affichage3+"'");

        RReste=reste - Quantite.toInt() ;
        Reste= QString::number(RReste) ;
        QString Reste1= QString::number(RReste) + " unite";


         prix1.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit+"' and idproduit='"+Idproduit+"'");
       if(prix1.next()){
           prix= prix1.value(0).toString();
       }


       tca1.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit+"' and idproduit='"+Idproduit+"'");
     if(tca1.next()){
         tca= tca1.value(0).toString() ;
     }

     int Totale=RReste * prix.toInt() + tca.toInt() ;
    QString totale1=QString::number(Totale);


        update.exec("UPDATE marchandise SET   quantite='"+Reste+"' , total='"+totale1+"' WHERE nom='"+Nomproduit+"' and idproduit='"+Idproduit+"'");
    }
      }
        //int rete=200;


    if(update.exec()){
        QMessageBox::information(this,"Message", "votre modification a ete fait avec succes");
       combo->clear();
        ui->prixventesortie->clear();
       ui->prixventevariation ->clear();
       ui->categorie ->clear();
         ui->remarque->clear();
        ui->quantite->clear();
        ui->anne ->clear();
        ui->mois->clear();
        ui->jour->clear();
        combo2->clear();
       db.close();
    }else{
        QMessageBox::critical(this,"Message", "erreur");

    }
      }else{
          QMessageBox::critical(this,"Message", "erreur2");

      }
    }




    }
    }
    }
}
void modifiervente::on_annuler_clicked()
{
    QMessageBox ::StandardButton reply = QMessageBox::question(this , "caisse","Voulez vous vraiment l annuler ?" , QMessageBox::Yes | QMessageBox::No );
    if( reply ==QMessageBox::Yes){
        close();


    }
    else{}
}


void modifiervente::on_id_clicked()
{
    db.open();
  combo2->clear();
    QString current=combo->currentText();

    QSqlQuery val;
    QString val1;
     QList<QString> valeur;
    val.exec("SELECT idproduit from marchandise where nom='"+current+"'");
    while(val.next()){
        valeur += val.value(0).toString();
    }
    //combo->insertAction( mouseDoubleClickEvent(),);
      combo2->addItems(valeur);

     // if(    QObject::connect(, SIGNAL(clicked()), this , SLOT(id()));

      db.close();
}

