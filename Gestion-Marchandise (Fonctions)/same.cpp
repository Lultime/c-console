#include "same.h"
#include "ui_same.h"
#include"QSqlQuery"
#include"QMessageBox"
#include"QDateTime"
#include"QPainter"
#include"QFileDialog"
#include"QtDebug"
#include"QSqlQueryModel"
#include"QVector"
#include"fichevente.h"
same::same(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::same)
{
    ui->setupUi(this);

}

same::~same()
{
    delete ui;
}

void same::on_pushButton_clicked()
{

}


void same::on_termine_clicked()
{
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();

    /*
    QVector<QString> Quantite;
    QVector<QString> Nomproduit2;
    QVector<QString> Prix_vente_sortie;
    QVector<QString> prix_vente_variation;
    QVector<QString> Categorie;
    QVector<QString> Anne;
    QVector<QString> mois;
    QVector<QString> jour;
    QVector<QString> Date;
    QVector<QString> Remarque;
    QVector<QString> Idproduit;
    QVector<QString> totale;


    Nomproduit2.append(ui->nomproduit_2->text());
    Nomproduit2.append(ui->nomproduit_2->text());
    Nomproduit2.append(ui->nomproduit_2->text());
    Nomproduit2.append(ui->nomproduit_2->text());
    Nomproduit2.append(ui->nomproduit_2->text());
    */
             //  1
  QString Nomproduit = ui->nomproduit ->text();
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
QString Idproduit=ui->idproduit->text();
int Totale=Quantite.toInt() * prix_vente_variation.toInt() ;
QString totale = QString::number(Totale) ;
QString totale1 = QString::number(Totale) + " Gourdes";
      //    2
QString Nomproduit2 = ui->nomproduit_2 ->text();
QString Quantite2 =ui->quantite_2 ->text() ;
QString Quantite12 =ui->quantite_2 ->text() + " unite";
QString Prix_vente_sortie2 =ui->prixventesortie_2->text() ;
QString prix_vente_variation2=ui->prixventevariation_2 ->text() ;
QString Prix_vente_sortie12 =ui->prixventesortie_2->text() + " Gourdes";
QString prix_vente_variation12=ui->prixventevariation_2 ->text() + " Gourdes";
QString Categorie2 =ui->categorie_2 ->toPlainText();
QString Remarque2 =ui->remarque_2->toPlainText();
QString Idproduit2=ui->idproduit_2->text();
int Totale2=Quantite2.toInt() * prix_vente_variation2.toInt() ;
QString totale2 = QString::number(Totale2) ;
QString totale12 = QString::number(Totale2) + " Gourdes";
                     // 3
QString Nomproduit3 = ui->nomproduit_3->text();
QString Quantite3 =ui->quantite_3 ->text() ;
QString Quantite13 =ui->quantite_3 ->text() + " unite";
QString Prix_vente_sortie3 =ui->prixventesortie_3->text() ;
QString prix_vente_variation3=ui->prixventevariation_3 ->text() ;
QString Prix_vente_sortie13 =ui->prixventesortie_3->text() + " Gourdes";
QString prix_vente_variation13=ui->prixventevariation_3 ->text() + " Gourdes";
QString Categorie3 =ui->categorie_3->toPlainText();
QString Remarque3 =ui->remarque_3->toPlainText();
QString Idproduit3=ui->idproduit_3->text();
int Totale3=Quantite3.toInt() * prix_vente_variation3.toInt() ;
QString totale3 = QString::number(Totale3) ;
QString totale13 = QString::number(Totale3) + " Gourdes";

                       // 4
QString Nomproduit4 = ui->nomproduit_4 ->text();
QString Quantite4 =ui->quantite_4 ->text() ;
QString Quantite14 =ui->quantite_4 ->text() + " unite";
QString Prix_vente_sortie4 =ui->prixventesortie_4->text() ;
QString prix_vente_variation4=ui->prixventevariation_4 ->text() ;
QString Prix_vente_sortie14 =ui->prixventesortie_4->text() + " Gourdes";
QString prix_vente_variation14=ui->prixventevariation_4 ->text() + " Gourdes";
QString Categorie4 =ui->categorie_4 ->toPlainText();
QString Remarque4 =ui->remarque_4->toPlainText();
QString Idproduit4=ui->idproduit_4->text();
int Totale4=Quantite4.toInt() * prix_vente_variation4.toInt() ;
QString totale4= QString::number(Totale4) ;
QString totale14 = QString::number(Totale4) + " Gourdes";
                     // 5

QString Nomproduit5 = ui->nomproduit_5 ->text();
QString Quantite5 =ui->quantite_5 ->text() ;
QString Quantite15 =ui->quantite_5 ->text() + " unite";
QString Prix_vente_sortie5 =ui->prixventesortie_5->text() ;
QString prix_vente_variation5=ui->prixventevariation_5 ->text() ;
QString Prix_vente_sortie15 =ui->prixventesortie_5->text() + " Gourdes";
QString prix_vente_variation15=ui->prixventevariation_5 ->text() + " Gourdes";
QString Categorie5 =ui->categorie_5 ->toPlainText();
QString Remarque5 =ui->remarque_5->toPlainText();
QString Idproduit5=ui->idproduit_5->text();
int Totale5=Quantite5.toInt() * prix_vente_variation5.toInt() ;
QString totale5 = QString::number(Totale5) ;
QString totale15 = QString::number(Totale5) + " Gourdes";









if(Nomproduit.isEmpty() || Quantite.isEmpty() || Prix_vente_sortie.isEmpty() || prix_vente_variation.isEmpty() || Categorie.isEmpty()){

   QMessageBox::critical(this,"Message", "Veuiller remplir tous les champs");
}else{
   if(!Nomproduit.isEmpty() && !Quantite.toInt() || !Prix_vente_sortie.toInt() || !prix_vente_variation.toInt() || Nomproduit.toInt() || Categorie.toInt() || !Nomproduit2.isEmpty()  &&! Quantite2.toInt() || !Prix_vente_sortie2.toInt() || !prix_vente_variation2.toInt() || Nomproduit2.toInt()  || Categorie2.toInt() /*|| !Nomproduit3.isEmpty() || !Quantite3.toInt() || !Prix_vente_sortie3.toInt() || !prix_vente_variation3.toInt() || Nomproduit3.toInt()  || Categorie3.toInt() || !Nomproduit4.isEmpty() || !Quantite4.toInt() || !Prix_vente_sortie4.toInt() || !prix_vente_variation4.toInt() || Nomproduit4.toInt()  || Categorie4.toInt() || !Nomproduit5.isEmpty() || !Quantite5.toInt() || !Prix_vente_sortie5.toInt() || !prix_vente_variation5.toInt() || Nomproduit5.toInt()  || Categorie5.toInt()*/ ){
        QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");

    }else{
 QSqlQuery select,select1,query,s2,s3,s4,s5,is2,is3,is4,is5,query2,query3,query4,query5;
   QString affichage="",affichage2,affichage3="",a2,a3,a4,a5,ia2,ia3,ia4,ia5;
   int affichage1;

    query = QSqlQuery("SELECT montant FROM comptevente");
    QString Reste,reste;
    if(query.next()){
       reste=query.value(0).toString() ;
       affichage1 = reste.toInt() + Totale + Totale2 + Totale3 + Totale4 + Totale5;

 }

    //    1  nom produit
 affichage3 =  QString::number(affichage1) ;
   select= QSqlQuery("SELECT nom FROM marchandise WHERE nom =\""+Nomproduit+"\"");
   if(select.next()){
       affichage = select.value(0).toString() ;

   }

     // 2 nom produit

   s2= QSqlQuery("SELECT nom FROM marchandise WHERE nom =\""+Nomproduit2+"\"");
   if(s2.next()){
       a2 = s2.value(0).toString();
   }

   //  3 nom produit
   s3= QSqlQuery("SELECT nom FROM marchandise WHERE nom=\""+Nomproduit3+"\"");
   if(s3.next()){
       a3= s3.value(0).toString();


   }
   // 4 nom produit
   s4= QSqlQuery("SELECT nom FROM marchandise WHERE nom =\""+Nomproduit4+"\"");
   if(s4.next()){
      a4 = s4.value(0).toString() ;


   }

   //5 nom produit
   s5= QSqlQuery("SELECT nom FROM marchandise WHERE nom =\""+Nomproduit5+"\"");
   if(s5.next()){
        a5 = s5.value(0).toString() ;

   }

   // 1  id produit


   select1= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit+"\"");

   if(select1.next()){
       affichage2 = select1.value(0).toString() ;
   }

           //2 id produit
   is2= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit2+"\"");

   if(is2.next()){
       ia2 = is2.value(0).toString() ;
   }
        // 3 id produit
   is3= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit3+"\"");

   if(is3.next()){
       ia3 = is3.value(0).toString() ;
   }
        // 4 id produit
   is4= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit4+"\"");

   if(is4.next()){
       ia4 = is4.value(0).toString() ;
   }
          // 5 id produit
   is5= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit5+"\"");

   if(is5.next()){
       ia5 = is5.value(0).toString() ;
   }

   if(!Nomproduit.isEmpty() && affichage.isEmpty() || affichage2 !=Idproduit || !Nomproduit2.isEmpty() && a2.isEmpty() || ia2 !=Idproduit2 || !Nomproduit3.isEmpty() && a3.isEmpty() || ia3 !=Idproduit3 || !Nomproduit4.isEmpty() && a4.isEmpty() || ia4 !=Idproduit4 || !Nomproduit5.isEmpty() && a5.isEmpty() || ia5 !=Idproduit5 ){
       QMessageBox::critical(this,"Message", "Ce produit n existe pas ou l'id ne correspond pas a ce produit");

       ui->nomproduit->clear();
       ui->idproduit->clear();

       ui->nomproduit_2->clear();
       ui->idproduit_2->clear();
       ui->nomproduit_3->clear();
       ui->idproduit_3->clear();
       ui->nomproduit_4->clear();
       ui->idproduit_4->clear();
       ui->nomproduit_5->clear();
       ui->idproduit_5->clear();

   }else{

       if(!Anne.toInt() || !mois.toInt() || !Jour.toInt()){
           QMessageBox::critical(this, "message","Format date incorrect ");


       }else{
           if(Anne.length() < 4 || Anne.length() == 3 || Anne.length() == 2 || Anne.length() == 1 || Anne.length() == 0 || mois.length() < 2 || mois.length() == 0 ||mois.length() == 1 || Jour.length() < 2 ||Jour.length() == 0 ||Jour.length() == 1){
               QMessageBox::critical(this, "message","Format date incorrect ");

           }else{
 QSqlQuery insert,update,update2,update3,update4,update5,update6,query,prix1,tca1,insert2,insert3,insert4,insert5,prix2,tca2,prix3,tca3,prix4,tca4,prix5,tca5;


update2.exec("UPDATE comptevente SET   montant='"+affichage3+"'");


QSqlQuery query1,query2,query3,query4,query5;
//   1
if(!Nomproduit.isEmpty()){
query1 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit+"\"");
if(query1.exec()){
int reste=0;
int RReste;
QString Reste,prix,tca;
if(query1.next()){
   reste=query1.value(0).toInt();

   if(reste < Quantite.toInt() ){
       QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit+"' requis non disponible");

   }else{
       int Int=1;
       QString Int1=QString::number(Int);
       insert = QSqlQuery("INSERT INTO vente ( nom, quantite, Prix , prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit+"','"+Quantite1+"','"+Prix_vente_sortie1+"','"+prix_vente_variation1+"','"+Categorie+"','"+Date+"','"+Remarque+"','"+totale1+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
       query = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit+"\"");

  RReste=reste - Quantite.toInt() ;
  Reste= QString::number(RReste) ;
  QString Reste1= QString::number(RReste) + " gourdes";


   prix1.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit+"'");
 if(prix1.next()){
     prix= prix1.value(0).toString();
 }


 tca1.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit+"'");
if(tca1.next()){
   tca= tca1.value(0).toString() ;
}

int Totale=RReste * prix.toInt() + tca.toInt() ;
QString totale1=QString::number(Totale);


  update.exec("UPDATE marchandise SET   quantite='"+Reste+"' , total='"+totale1+"' WHERE nom='"+Nomproduit+"' and idproduit='"+affichage2+"'");
}
}
}else{
    QMessageBox::critical(this,"message","erreur fatale");
}
}
  //int rete=200;

        // 2
if(!Nomproduit2.isEmpty()){
   query2 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit2+"\"");

   int reste2=0;
   int RReste2;
   QString Reste2,prix22,tca22;
   if(query2.next()){
      reste2=query2.value(0).toInt();

      if(reste2 < Quantite2.toInt() ){
          QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit2+"' requis non disponible");

      }else{
          int Int=1;
          QString Int1=QString::number(Int);
          insert2 = QSqlQuery("INSERT INTO vente ( nom, quantite, prix , prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit2+"','"+Quantite12+"','"+Prix_vente_sortie12+"','"+prix_vente_variation12+"','"+Categorie2+"','"+Date+"','"+Remarque+"','"+totale12+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
          query2 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit2+"\"");

     RReste2=reste2 - Quantite2.toInt() ;
     Reste2= QString::number(RReste2) ;
     QString Reste22= QString::number(RReste2) + " gourdes";


      prix2.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit2+"'");
    if(prix2.next()){
        prix22= prix2.value(0).toString();
    }


    tca2.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit2+"'");
   if(tca2.next()){
      tca22= tca2.value(0).toString() ;
   }

   int Totale2=RReste2 * prix22.toInt() + tca22.toInt() ;
   QString totale2=QString::number(Totale2);


     update3.exec("UPDATE marchandise SET   quantite='"+Reste2+"' , total='"+totale2+"' WHERE nom='"+Nomproduit2+"' and idproduit='"+ia2+"'");
   }
   }
}
    // 3
if(!Nomproduit3.isEmpty()){
      query3 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit3+"\"");

      int reste3=0;
      int RReste3;
      QString Reste3,prix33,tca33;
      if(query3.next()){
         reste3=query3.value(0).toInt();

         if(reste3 < Quantite3.toInt() ){
             QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit3+"' requis non disponible");

         }else{
             int Int=1;
             QString Int1=QString::number(Int);
             insert3 = QSqlQuery("INSERT INTO vente ( nom, quantite, Prix, prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit3+"','"+Quantite13+"','"+Prix_vente_sortie13+"','"+prix_vente_variation13+"','"+Categorie3+"','"+Date+"','"+Remarque+"','"+totale13+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
             query3 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit3+"\"");

        RReste3=reste3 - Quantite3.toInt() ;
        Reste3= QString::number(RReste3) ;
        QString Reste33= QString::number(RReste3) + " gourdes";


         prix3.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit3+"'");
       if(prix3.next()){
           prix33= prix3.value(0).toString();
       }


       tca3.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit3+"'");
      if(tca3.next()){
         tca33= tca3.value(0).toString() ;
      }

      int Totale3=RReste3 * prix33.toInt() + tca33.toInt() ;
      QString totale3=QString::number(Totale3);


        update4.exec("UPDATE marchandise SET   quantite='"+Reste3+"' , total='"+totale3+"' WHERE nom='"+Nomproduit3+"' and idproduit='"+ia3+"'");
      }
}
}
         // 4
if(!Nomproduit4.isEmpty()){
         query4 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom=\""+Nomproduit4+"\"");

         int reste4=0;
         int RReste4;
         QString Reste4,prix44,tca44;
         if(query4.next()){
            reste4=query4.value(0).toInt();

            if(reste4 < Quantite4.toInt() ){
                QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit4+"' requis non disponible");

            }else{
                int Int=1;
                QString Int1=QString::number(Int);
                insert4 = QSqlQuery("INSERT INTO vente ( nom, quantite, Prix , prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit4+"','"+Quantite14+"','"+Prix_vente_sortie14+"','"+prix_vente_variation14+"','"+Categorie4+"','"+Date+"','"+Remarque+"','"+totale14+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
                query4 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit4+"\"");

           RReste4=reste4 - Quantite4.toInt() ;
           Reste4= QString::number(RReste4) ;
           QString Reste44= QString::number(RReste4) + " gourdes";


            prix4.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit4+"'");
          if(prix4.next()){
              prix44= prix4.value(0).toString();
          }


          tca4.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit4+"'");
         if(tca4.next()){
            tca44= tca4.value(0).toString() ;
         }

         int Totale4=RReste4 * prix44.toInt() + tca44.toInt() ;
         QString totale4=QString::number(Totale4);


           update5.exec("UPDATE marchandise SET   quantite='"+Reste4+"' , total='"+totale4+"' WHERE nom='"+Nomproduit4+"' and idproduit='"+ia4+"'");
         }
}
}
            //5
if(!Nomproduit5.isEmpty()){
            query5 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit5+"\"");

            int reste5=0;
            int RReste5;
            QString Reste5,prix55,tca55;
            if(query5.next()){
               reste5=query5.value(0).toInt();

               if(reste5 < Quantite5.toInt() ){
                   QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit5+"' requis non disponible");

               }else{

                   int Int=1;
                   QString Int1=QString::number(Int);
                   insert5 = QSqlQuery("INSERT INTO vente ( nom, quantite, Prix , prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit5+"','"+Quantite15+"','"+Prix_vente_sortie15+"','"+prix_vente_variation15+"','"+Categorie5+"','"+Date+"','"+Remarque+"','"+totale15+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
                   query5 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom=\""+Nomproduit5+"\"");

              RReste5=reste5 - Quantite5.toInt() ;
              Reste5= QString::number(RReste5) ;
              QString Reste55= QString::number(RReste5) + " gourdes";


               prix5.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit5+"'");
             if(prix5.next()){
                 prix55= prix5.value(0).toString();
             }


             tca5.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit5+"'");
            if(tca5.next()){
               tca55= tca5.value(0).toString() ;
            }

            int Totale5=RReste5 * prix55.toInt() + tca55.toInt() ;
            QString totale5=QString::number(Totale5);


              update6.exec("UPDATE marchandise SET   quantite='"+Reste5+"' , total='"+totale5+"' WHERE nom='"+Nomproduit5+"' and idproduit='"+ia5+"'");
            }
}
}


if(update.exec()){
  QMessageBox::information(this,"Message", "votre fiche de vente a ete fait avec succes");
 ui->nomproduit->clear();
  ui->prixventesortie->clear();
 ui->prixventevariation ->clear();
 ui->categorie ->clear();
 ui->idproduit->clear();
   ui->remarque->clear();
  ui->quantite->clear();
  // 2
  ui->nomproduit_2->clear();
   ui->prixventesortie_2->clear();
  ui->prixventevariation_2 ->clear();
  ui->categorie_2 ->clear();
  ui->idproduit_2->clear();
    ui->remarque_2->clear();
   ui->quantite_2->clear();
   //3
   ui->nomproduit_3->clear();
    ui->prixventesortie_3->clear();
   ui->prixventevariation_3 ->clear();
   ui->categorie_3 ->clear();
   ui->idproduit_3->clear();
     ui->remarque_3->clear();
    ui->quantite_3->clear();
    //4
    ui->nomproduit_4->clear();
     ui->prixventesortie_4->clear();
    ui->prixventevariation_4 ->clear();
    ui->categorie_4 ->clear();
    ui->idproduit_4->clear();
      ui->remarque_4->clear();
     ui->quantite_4->clear();
     // 5
     ui->nomproduit_5->clear();
      ui->prixventesortie_5->clear();
     ui->prixventevariation_5 ->clear();
     ui->categorie_5 ->clear();
     ui->idproduit_5->clear();
       ui->remarque_5->clear();
      ui->quantite_5->clear();
  ui->anne ->clear();
  ui->mois->clear();
  ui->jour->clear();




  fichevente * Fichevente =new  fichevente();
   Fichevente->show();






 db.close();
}else{
  QMessageBox::critical(this,"Message", "erreur");

}

}




}
}
}


}
}

void same::on_autreproduit_clicked()
{
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

    /*
    QVector<QString> Quantite;
    QVector<QString> Nomproduit2;
    QVector<QString> Prix_vente_sortie;
    QVector<QString> prix_vente_variation;
    QVector<QString> Categorie;
    QVector<QString> Anne;
    QVector<QString> mois;
    QVector<QString> jour;
    QVector<QString> Date;
    QVector<QString> Remarque;
    QVector<QString> Idproduit;
    QVector<QString> totale;


    Nomproduit2.append(ui->nomproduit_2->text());
    Nomproduit2.append(ui->nomproduit_2->text());
    Nomproduit2.append(ui->nomproduit_2->text());
    Nomproduit2.append(ui->nomproduit_2->text());
    Nomproduit2.append(ui->nomproduit_2->text());
    */
             //  1
  QString Nomproduit = ui->nomproduit ->text();
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
QString Idproduit=ui->idproduit->text();
int Totale=Quantite.toInt() * prix_vente_variation.toInt() ;
QString totale = QString::number(Totale) ;
QString totale1 = QString::number(Totale) + " Gourdes";
      //    2
QString Nomproduit2 = ui->nomproduit_2 ->text();
QString Quantite2 =ui->quantite_2 ->text() ;
QString Quantite12 =ui->quantite_2 ->text() + " unite";
QString Prix_vente_sortie2 =ui->prixventesortie_2->text() ;
QString prix_vente_variation2=ui->prixventevariation_2 ->text() ;
QString Prix_vente_sortie12 =ui->prixventesortie_2->text() + " Gourdes";
QString prix_vente_variation12=ui->prixventevariation_2 ->text() + " Gourdes";
QString Categorie2 =ui->categorie_2 ->toPlainText();
QString Remarque2 =ui->remarque_2->toPlainText();
QString Idproduit2=ui->idproduit_2->text();
int Totale2=Quantite2.toInt() * prix_vente_variation2.toInt() ;
QString totale2 = QString::number(Totale2) ;
QString totale12 = QString::number(Totale2) + " Gourdes";
                     // 3
QString Nomproduit3 = ui->nomproduit_3->text();
QString Quantite3 =ui->quantite_3 ->text() ;
QString Quantite13 =ui->quantite_3 ->text() + " unite";
QString Prix_vente_sortie3 =ui->prixventesortie_3->text() ;
QString prix_vente_variation3=ui->prixventevariation_3 ->text() ;
QString Prix_vente_sortie13 =ui->prixventesortie_3->text() + " Gourdes";
QString prix_vente_variation13=ui->prixventevariation_3 ->text() + " Gourdes";
QString Categorie3 =ui->categorie_3->toPlainText();
QString Remarque3 =ui->remarque_3->toPlainText();
QString Idproduit3=ui->idproduit_3->text();
int Totale3=Quantite3.toInt() * prix_vente_variation3.toInt() ;
QString totale3 = QString::number(Totale3) ;
QString totale13 = QString::number(Totale3) + " Gourdes";

                       // 4
QString Nomproduit4 = ui->nomproduit_4 ->text();
QString Quantite4 =ui->quantite_4 ->text() ;
QString Quantite14 =ui->quantite_4 ->text() + " unite";
QString Prix_vente_sortie4 =ui->prixventesortie_4->text() ;
QString prix_vente_variation4=ui->prixventevariation_4 ->text() ;
QString Prix_vente_sortie14 =ui->prixventesortie_4->text() + " Gourdes";
QString prix_vente_variation14=ui->prixventevariation_4 ->text() + " Gourdes";
QString Categorie4 =ui->categorie_4 ->toPlainText();
QString Remarque4 =ui->remarque_4->toPlainText();
QString Idproduit4=ui->idproduit_4->text();
int Totale4=Quantite4.toInt() * prix_vente_variation4.toInt() ;
QString totale4= QString::number(Totale4) ;
QString totale14 = QString::number(Totale4) + " Gourdes";
                     // 5

QString Nomproduit5 = ui->nomproduit_5 ->text();
QString Quantite5 =ui->quantite_5 ->text() ;
QString Quantite15 =ui->quantite_5 ->text() + " unite";
QString Prix_vente_sortie5 =ui->prixventesortie_5->text() ;
QString prix_vente_variation5=ui->prixventevariation_5 ->text() ;
QString Prix_vente_sortie15 =ui->prixventesortie_5->text() + " Gourdes";
QString prix_vente_variation15=ui->prixventevariation_5 ->text() + " Gourdes";
QString Categorie5 =ui->categorie_5 ->toPlainText();
QString Remarque5 =ui->remarque_5->toPlainText();
QString Idproduit5=ui->idproduit_5->text();
int Totale5=Quantite5.toInt() * prix_vente_variation5.toInt() ;
QString totale5 = QString::number(Totale5) ;
QString totale15 = QString::number(Totale5) + " Gourdes";









if(Nomproduit.isEmpty() || Quantite.isEmpty() || Prix_vente_sortie.isEmpty() || prix_vente_variation.isEmpty() || Categorie.isEmpty()){

   QMessageBox::critical(this,"Message", "Veuiller remplir tous les champs");
}else{
   if(!Nomproduit.isEmpty() && !Quantite.toInt() || !Prix_vente_sortie.toInt() || !prix_vente_variation.toInt() || Nomproduit.toInt()  || Categorie.toInt()){
        QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");

        if( !Nomproduit2.isEmpty() && !Quantite2.toInt() || !Prix_vente_sortie2.toInt() || !prix_vente_variation2.toInt() || Nomproduit2.toInt()  || Categorie2.toInt()){
         QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");
         if(!Nomproduit3.isEmpty() && !Quantite3.toInt() || !Prix_vente_sortie3.toInt() || !prix_vente_variation3.toInt() || Nomproduit3.toInt()  || Categorie3.toInt()){
              QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");
              if( !Nomproduit4.isEmpty() && !Quantite4.toInt() || !Prix_vente_sortie4.toInt() || !prix_vente_variation4.toInt() || Nomproduit4.toInt()  || Categorie4.toInt()){
                   QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");
                   if( !Nomproduit5.isEmpty() && !Quantite5.toInt() || !Prix_vente_sortie5.toInt() || !prix_vente_variation5.toInt() || Nomproduit5.toInt()  || Categorie5.toInt()){
                        QMessageBox::critical(this, "Information incorrecte","les chiffres et les lettres ne sont pas verifies");
                   }
              }
         }
        }

    }else{
 QSqlQuery select,select1,query,s2,s3,s4,s5,is2,is3,is4,is5,query2,query3,query4,query5;
   QString affichage="",affichage2,affichage3="",a2,a3,a4,a5,ia2,ia3,ia4,ia5;
   int affichage1;

    query = QSqlQuery("SELECT montant FROM comptevente");
    QString Reste,reste;
    if(query.next()){
       reste=query.value(0).toString() ;
 }
    affichage1 = reste.toInt() + Totale + Totale2 + Totale3 + Totale4 + Totale5;

    //    1  nom produit
 affichage3 =  QString::number(affichage1) ;
   select= QSqlQuery("SELECT nom FROM marchandise WHERE nom =\""+Nomproduit+"\"");
   if(select.next()){
       affichage = select.value(0).toString() ;

   }

     // 2 nom produit

   s2= QSqlQuery("SELECT nom FROM marchandise WHERE nom =\""+Nomproduit2+"\"");
   if(s2.next()){
       a2 = s2.value(0).toString();
   }

   //  3 nom produit
   s3= QSqlQuery("SELECT nom FROM marchandise WHERE nom=\""+Nomproduit3+"\"");
   if(s3.next()){
       a3= s3.value(0).toString();


   }
   // 4 nom produit
   s4= QSqlQuery("SELECT nom FROM marchandise WHERE nom =\""+Nomproduit4+"\"");
   if(s4.next()){
      a4 = s4.value(0).toString() ;


   }

   //5 nom produit
   s5= QSqlQuery("SELECT nom FROM marchandise WHERE nom =\""+Nomproduit5+"\"");
   if(s5.next()){
        a5 = s5.value(0).toString() ;

   }

   // 1  id produit


   select1= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit+"\"");

   if(select1.next()){
       affichage2 = select1.value(0).toString() ;
   }

           //2 id produit
   is2= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit2+"\"");

   if(is2.next()){
       ia2 = is2.value(0).toString() ;
   }
        // 3 id produit
   is3= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit3+"\"");

   if(is3.next()){
       ia3 = is3.value(0).toString() ;
   }
        // 4 id produit
   is4= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit4+"\"");

   if(is4.next()){
       ia4 = is4.value(0).toString() ;
   }
          // 5 id produit
   is5= QSqlQuery("SELECT idproduit  FROM marchandise WHERE nom =\""+Nomproduit5+"\"");

   if(is5.next()){
       ia5 = is5.value(0).toString() ;
   }

   if(!Nomproduit.isEmpty() && affichage.isEmpty() || affichage2 !=Idproduit || !Nomproduit2.isEmpty() && a2.isEmpty() || ia2 !=Idproduit2 || !Nomproduit3.isEmpty() && a3.isEmpty() || ia3 !=Idproduit3 || !Nomproduit4.isEmpty() && a4.isEmpty() || ia4 !=Idproduit4 || !Nomproduit5.isEmpty() && a5.isEmpty() || ia5 !=Idproduit5 ){
       QMessageBox::critical(this,"Message", "Ce produit n existe pas ou l'id ne correspond pas a ce produit");

       ui->nomproduit->clear();
       ui->idproduit->clear();

       ui->nomproduit_2->clear();
       ui->idproduit_2->clear();
       ui->nomproduit_3->clear();
       ui->idproduit_3->clear();
       ui->nomproduit_4->clear();
       ui->idproduit_4->clear();
       ui->nomproduit_5->clear();
       ui->idproduit_5->clear();

   }else{

       if(!Anne.toInt() || !mois.toInt() || !Jour.toInt()){
           QMessageBox::critical(this, "message","Format date incorrect ");


       }else{
           if(Anne.length() < 4 || Anne.length() == 3 || Anne.length() == 2 || Anne.length() == 1 || Anne.length() == 0 || mois.length() < 2 || mois.length() == 0 ||mois.length() == 1 || Jour.length() < 2 ||Jour.length() == 0 ||Jour.length() == 1){
               QMessageBox::critical(this, "message","Format date incorrect ");

           }else{
 QSqlQuery insert,update,update2,update3,update4,update5,update6,query,prix1,tca1,insert2,insert3,insert4,insert5,prix2,tca2,prix3,tca3,prix4,tca4,prix5,tca5;


update2.exec("UPDATE comptevente SET   montant='"+affichage3+"'");


QSqlQuery query1,query2,query3,query4,query5;
//   1
if(!Nomproduit.isEmpty()){
query1 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit+"\"");
if(query1.exec()){
int reste=0;
int RReste;
QString Reste,prix,tca;
if(query1.next()){
   reste=query1.value(0).toInt();

   if(reste < Quantite.toInt() ){
       QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit+"' requis non disponible");

   }else{
       int Int=1;
       QString Int1=QString::number(Int);
       insert = QSqlQuery("INSERT INTO vente ( nom, quantite, Prix , prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit+"','"+Quantite1+"','"+Prix_vente_sortie1+"','"+prix_vente_variation1+"','"+Categorie+"','"+Date+"','"+Remarque+"','"+totale1+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
       query = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit+"\"");

  RReste=reste - Quantite.toInt() ;
  Reste= QString::number(RReste) ;
  QString Reste1= QString::number(RReste) + " gourdes";


   prix1.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit+"'");
 if(prix1.next()){
     prix= prix1.value(0).toString();
 }


 tca1.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit+"'");
if(tca1.next()){
   tca= tca1.value(0).toString() ;
}

int Totale=RReste * prix.toInt() + tca.toInt() ;
QString totale1=QString::number(Totale);


  update.exec("UPDATE marchandise SET   quantite='"+Reste+"' , total='"+totale1+"' WHERE nom='"+Nomproduit+"' and idproduit='"+affichage2+"'");
}
}
}else{
    QMessageBox::critical(this,"message","erreur fatale");
}
}
  //int rete=200;

        // 2
if(!Nomproduit2.isEmpty()){
   query2 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit2+"\"");

   int reste2=0;
   int RReste2;
   QString Reste2,prix22,tca22;
   if(query2.next()){
      reste2=query2.value(0).toInt();

      if(reste2 < Quantite2.toInt() ){
          QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit2+"' requis non disponible");

      }else{
          int Int=1;
          QString Int1=QString::number(Int);
          insert2 = QSqlQuery("INSERT INTO vente ( nom, quantite, prix , prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit2+"','"+Quantite12+"','"+Prix_vente_sortie12+"','"+prix_vente_variation12+"','"+Categorie2+"','"+Date+"','"+Remarque+"','"+totale12+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
          query2 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit2+"\"");

     RReste2=reste2 - Quantite2.toInt() ;
     Reste2= QString::number(RReste2) ;
     QString Reste22= QString::number(RReste2) + " gourdes";


      prix2.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit2+"'");
    if(prix2.next()){
        prix22= prix2.value(0).toString();
    }


    tca2.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit2+"'");
   if(tca2.next()){
      tca22= tca2.value(0).toString() ;
   }

   int Totale2=RReste2 * prix22.toInt() + tca22.toInt() ;
   QString totale2=QString::number(Totale2);


     update3.exec("UPDATE marchandise SET   quantite='"+Reste2+"' , total='"+totale2+"' WHERE nom='"+Nomproduit2+"' and idproduit='"+ia2+"'");
   }
   }
}
    // 3
if(!Nomproduit3.isEmpty()){
      query3 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit3+"\"");

      int reste3=0;
      int RReste3;
      QString Reste3,prix33,tca33;
      if(query3.next()){
         reste3=query3.value(0).toInt();

         if(reste3 < Quantite3.toInt() ){
             QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit3+"' requis non disponible");

         }else{
             int Int=1;
             QString Int1=QString::number(Int);
             insert3 = QSqlQuery("INSERT INTO vente ( nom, quantite, Prix, prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit3+"','"+Quantite13+"','"+Prix_vente_sortie13+"','"+prix_vente_variation13+"','"+Categorie3+"','"+Date+"','"+Remarque+"','"+totale13+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
             query3 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit3+"\"");

        RReste3=reste3 - Quantite3.toInt() ;
        Reste3= QString::number(RReste3) ;
        QString Reste33= QString::number(RReste3) + " gourdes";


         prix3.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit3+"'");
       if(prix3.next()){
           prix33= prix3.value(0).toString();
       }


       tca3.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit3+"'");
      if(tca3.next()){
         tca33= tca3.value(0).toString() ;
      }

      int Totale3=RReste3 * prix33.toInt() + tca33.toInt() ;
      QString totale3=QString::number(Totale3);


        update4.exec("UPDATE marchandise SET   quantite='"+Reste3+"' , total='"+totale3+"' WHERE nom='"+Nomproduit3+"' and idproduit='"+ia3+"'");
      }
}
}
         // 4
if(!Nomproduit4.isEmpty()){
         query4 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom=\""+Nomproduit4+"\"");

         int reste4=0;
         int RReste4;
         QString Reste4,prix44,tca44;
         if(query4.next()){
            reste4=query4.value(0).toInt();

            if(reste4 < Quantite4.toInt() ){
                QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit4+"' requis non disponible");

            }else{
                int Int=1;
                QString Int1=QString::number(Int);
                insert4 = QSqlQuery("INSERT INTO vente ( nom, quantite, Prix , prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit4+"','"+Quantite14+"','"+Prix_vente_sortie14+"','"+prix_vente_variation14+"','"+Categorie4+"','"+Date+"','"+Remarque+"','"+totale14+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
                query4 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit4+"\"");

           RReste4=reste4 - Quantite4.toInt() ;
           Reste4= QString::number(RReste4) ;
           QString Reste44= QString::number(RReste4) + " gourdes";


            prix4.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit4+"'");
          if(prix4.next()){
              prix44= prix4.value(0).toString();
          }


          tca4.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit4+"'");
         if(tca4.next()){
            tca44= tca4.value(0).toString() ;
         }

         int Totale4=RReste4 * prix44.toInt() + tca44.toInt() ;
         QString totale4=QString::number(Totale4);


           update5.exec("UPDATE marchandise SET   quantite='"+Reste4+"' , total='"+totale4+"' WHERE nom='"+Nomproduit4+"' and idproduit='"+ia4+"'");
         }
}
}
            //5
if(!Nomproduit5.isEmpty()){
            query5 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom =\""+Nomproduit5+"\"");

            int reste5=0;
            int RReste5;
            QString Reste5,prix55,tca55;
            if(query5.next()){
               reste5=query5.value(0).toInt();

               if(reste5 < Quantite5.toInt() ){
                   QMessageBox::critical(this,"Message", "Quantite de '"+Nomproduit5+"' requis non disponible");

               }else{

                   int Int=1;
                   QString Int1=QString::number(Int);
                   insert5 = QSqlQuery("INSERT INTO vente ( nom, quantite, Prix , prix_2, Categorie,date, remarque ,total,somme,anne,mois,jour,cle) values('"+Nomproduit5+"','"+Quantite15+"','"+Prix_vente_sortie15+"','"+prix_vente_variation15+"','"+Categorie5+"','"+Date+"','"+Remarque+"','"+totale15+"','"+affichage3+"','"+ Anne+"','"+ mois+"','"+ Jour+"','"+Int1+"')");
                   query5 = QSqlQuery("SELECT quantite  FROM marchandise WHERE nom=\""+Nomproduit5+"\"");

              RReste5=reste5 - Quantite5.toInt() ;
              Reste5= QString::number(RReste5) ;
              QString Reste55= QString::number(RReste5) + " gourdes";


               prix5.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit5+"'");
             if(prix5.next()){
                 prix55= prix5.value(0).toString();
             }


             tca5.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit5+"'");
            if(tca5.next()){
               tca55= tca5.value(0).toString() ;
            }

            int Totale5=RReste5 * prix55.toInt() + tca55.toInt() ;
            QString totale5=QString::number(Totale5);


              update6.exec("UPDATE marchandise SET   quantite='"+Reste5+"' , total='"+totale5+"' WHERE nom='"+Nomproduit5+"' and idproduit='"+ia5+"'");
            }
}
}


if(update.exec()){
  QMessageBox::information(this,"Message", "votre fiche de vente a ete fait avec succes");
 ui->nomproduit->clear();
  ui->prixventesortie->clear();
 ui->prixventevariation ->clear();
 ui->categorie ->clear();
 ui->idproduit->clear();
   ui->remarque->clear();
  ui->quantite->clear();
  // 2
  ui->nomproduit_2->clear();
   ui->prixventesortie_2->clear();
  ui->prixventevariation_2 ->clear();
  ui->categorie_2 ->clear();
  ui->idproduit_2->clear();
    ui->remarque_2->clear();
   ui->quantite_2->clear();
   //3
   ui->nomproduit_3->clear();
    ui->prixventesortie_3->clear();
   ui->prixventevariation_3 ->clear();
   ui->categorie_3 ->clear();
   ui->idproduit_3->clear();
     ui->remarque_3->clear();
    ui->quantite_3->clear();
    //4
    ui->nomproduit_4->clear();
     ui->prixventesortie_4->clear();
    ui->prixventevariation_4 ->clear();
    ui->categorie_4 ->clear();
    ui->idproduit_4->clear();
      ui->remarque_4->clear();
     ui->quantite_4->clear();
     // 5
     ui->nomproduit_5->clear();
      ui->prixventesortie_5->clear();
     ui->prixventevariation_5 ->clear();
     ui->categorie_5 ->clear();
     ui->idproduit_5->clear();
       ui->remarque_5->clear();
      ui->quantite_5->clear();
  ui->anne ->clear();
  ui->mois->clear();
  ui->jour->clear();




  fichevente * Fichevente =new  fichevente();
   Fichevente->show();






 db.close();
}else{
  QMessageBox::critical(this,"Message", "erreur");

}

}




}
}
}

}
}




void same::on_annuler_clicked()
{

    int Int=1;
    QString Int1=QString::number(Int);
    QSqlQuery Delete;

    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();
/*

     QSqlQuery query1,query2,query3,query4,query5,query6,query7,query8,prix1,tca1,query9,query10,query11;
     QString test;

         QString quantite,montant,nomproduit,quantite2,quantiteinit1,total,prix,tca,total1,montantfinal,montant1,sum;
         int quantiteinit;
         query3.exec("SELECT quantite from vente  where cle='"+Int1+"'");
         if(query3.next()){
             quantite = query3.value(0).toString();
         }
         query6.exec("SELECT nom from vente  where cle='"+Int1+"'");
         if(query6.next()){
             nomproduit= query6.value(0).toString();
         }
      query5.exec("SELECT quantite from marchandise where nom='"+nomproduit+"'");
         if(query5.next()){
             quantite2 = query5.value(0).toString();
         }
         quantiteinit= quantite2.toInt() + quantite.toInt() ;
         quantiteinit1 =QString::number(quantiteinit) + " unite";
        query7.exec("SELECT total from marchandise where nom='"+nomproduit+"'");
        if(query7.next()){
            total = query7.value(0).toString();
        }
        prix1.exec("SELECT prix from marchandise WHERE nom='"+nomproduit+"'");
      if(prix1.next()){
          prix= prix1.value(0).toString();
      }


      tca1.exec("SELECT tca from marchandise WHERE nom='"+nomproduit+"'");
    if(tca1.next()){
        tca= tca1.value(0).toString();
    }

    int Totale= quantiteinit* prix.toInt() + tca.toInt() ;
    total1=QString::number(Totale) + "Gourdes";

       query4.exec("UPDATE marchandise set quantite='"+quantiteinit1+"' , total ='"+ total1+"'  WHERE nom='"+nomproduit+"'");
         query8.exec("SELECT montant from comptevente");
         if(query8.next()){
             montantfinal= query8.value(0).toString();
         }
         query10.exec("SELECT total from vente  WHERE nom='"+nomproduit+"'");
         if(query10.next()){
            montant1= query10.value(0).toString();
         }
         int montant2= montantfinal.toInt() - montant1.toInt();
         QString montant3=QString::number(montant2) + " Gourdes";
       query9.exec("UPDATE comptevente set montant='"+ montant3+"'");

   //  query11.exec("SELECT SUM(total) from marchandise ");
   //  if(query11.next()){
  //       sum= query11.value(0).toString();
  //   }
    // query12.exec("update
       */
       QMessageBox ::StandardButton reply = QMessageBox::question(this , "caisse","Voulez vous vraiment l annuler ?" , QMessageBox::Yes | QMessageBox::No );
       if( reply ==QMessageBox::Yes){
           Delete.exec("DELETE FROM vente where cle="+Int1);
           close();

       }
       else{}
  //  query1.clear();
    db.close();
}




