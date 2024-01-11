#include "listevente.h"
#include "ui_listevente.h"
#include "QMessageBox"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include "QFileDialog"
#include"QFile"
#include"QTextStream"
listevente::listevente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listevente)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente");
    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(total) from vente");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}
 ui->montant->setText(montant);
somme.exec("SELECT SUM( quantite) from vente");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}

 ui->quantite->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);

   query.clear();

}

listevente::~listevente()
{
    delete ui;
}

void listevente::on_supprimer_clicked()
{

    db.open();


     QSqlQuery query1,query2,query3,query4,query5,query6,query7,query8,prix1,tca1,query9,query10,query11;
     QString test;
     QString Idcaisse = ui->idcaisse->text();
     query2.exec("SELECT idvente from vente where idvente='"+Idcaisse+"'");
     if(query2.next()){
         test = query2.value(0).toString();
     }
     if(test.isEmpty()){
         QMessageBox::critical(this,"Message", " erreur d'id");
         ui->idcaisse->clear();
     }else{
         QString quantite,montant,nomproduit,quantite2,quantiteinit1,total,prix,tca,total1,montantfinal,montant1,sum;
         int quantiteinit;
         query3.exec("SELECT quantite from vente WHERE idvente='"+Idcaisse+"'");
         if(query3.next()){
             quantite = query3.value(0).toString();
         }
         query6.exec("SELECT nom from vente where  idvente='"+Idcaisse+"'");
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
    query1.exec("DELETE FROM vente WHERE idvente="+Idcaisse);

    QMessageBox::information(this,"Message", " Supprimer avec succes");
    ui->idcaisse->clear();
    db.open();
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente");
    QSqlQuery somme;


somme.exec("SELECT SUM(total) from vente");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";

}
 ui->montant->setText(montant);
somme.exec("SELECT SUM( quantite) from vente");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}

 ui->quantite->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);

   query.clear();
    query1.clear();

}
}

void listevente::on_listerfond_clicked()
{

    db.open();
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente");
    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(total) from vente");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";

}
 ui->montant->setText(montant);
somme.exec("SELECT SUM( quantite) from vente");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}

 ui->quantite->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);

   query.clear();

}


void listevente::on_mois_2_clicked()
{

    db.open();

    QString mois = ui->mois->text();
    if(mois.isEmpty()){
        QMessageBox::critical(this,"message","veuiller entrer le mois de recherche ");
    }else{
        if(!mois.toInt()){
            QMessageBox::critical(this,"message","veuiller entrer le mois en chiffre ");

        }else{
            QSqlQuery recherche,query;

            recherche.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente where mois ='"+mois+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(total) from vente where mois ='"+mois+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
          ui->montant->setText(montant);
         somme.exec("SELECT SUM(quantite) from vente where mois ='"+mois+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " unite";
         }

         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{

          ui->quantite->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView->setModel(modal);


                ui->mois->clear();


               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void listevente::on_jour_2_clicked()
{

    db.open();

    QString jour = ui->jour->text();
    if(jour.isEmpty()){
        QMessageBox::critical(this,"message","veuiller entrer le jour de recherche ");
    }else{
        if(!jour.toInt()){
            QMessageBox::critical(this,"message","veuiller entrer le jour en chiffre ");

        }else{
            QSqlQuery recherche,query;

            recherche.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente where jour ='"+jour+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(total) from vente where jour ='"+jour+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         ui->montant->setText(montant);

         somme.exec("SELECT SUM(quantite) from vente where jour ='"+jour+"'");
         if(somme.next()){
             montant= somme.value(0).toString()+ " unite";
         }

         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{
          ui->quantite->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView->setModel(modal);


                ui->jour->clear();


               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void listevente::on_anne_2_clicked()
{

    db.open();

    QString anne = ui->anne->text();
    if(anne.isEmpty()){
        QMessageBox::critical(this,"message","veuiller entrer l annee recherche");
    }else{
        if(!anne.toInt()){
            QMessageBox::critical(this,"message","veuiller entrer l annee en chiffre ");

        }else{
            QSqlQuery recherche,query;

            recherche.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente where anne ='"+anne+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(total) from vente where anne ='"+anne+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         ui->montant->setText(montant);

         somme.exec("SELECT SUM( quantite) from vente where anne ='"+anne+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " unite";
         }
         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{

          ui-> quantite->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView->setModel(modal);


             ui->anne->clear();
               query.clear();
            }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void listevente::on_tout_clicked()
{

    db.open();
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente");
    QSqlQueryModel * modal =new QSqlQueryModel();

    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(total) from vente");
if(somme.next()){
 montant= somme.value(0).toString()+ " gourdes";
}
ui->montant->setText(montant);
somme.exec("SELECT SUM(quantite) from vente ");
if(somme.next()){
    montant= somme.value(0).toString() + " unite";
}
ui->quantite->setText(montant);
    modal->setQuery(query);

    ui->tableView->setModel(modal);

   query.clear();

}


void listevente::on_pushButton_clicked()
{



    db.open();
    QSqlQuery recherche;
    QString recherche1;
    QString valeur=ui->nomproduit->text();

    recherche.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente where nom='"+valeur+"'");
    if(recherche.next()){
        recherche1 = recherche.value(0).toString();
    }

    if(recherche1.isEmpty()){
        QMessageBox::critical(this,"message"," produit non disponible ");
    }else{
        QSqlQuery somme;
        QString montant;

 somme.exec("SELECT SUM(total) from vente where nom ='"+valeur+"'");
 if(somme.next()){
     montant= somme.value(0).toString()+ " gourdes";
 }
 ui->montant->setText(montant);
 somme.exec("SELECT SUM(quantite) from vente where nom ='"+valeur+"'");
 if(somme.next()){
     montant= somme.value(0).toString() + " unite";
 }
 ui->quantite->setText(montant);

        QSqlQueryModel * modal =new QSqlQueryModel();

        modal->setQuery(recherche);

        ui->tableView   ->setModel(modal);
       recherche.clear();

    }

}


void listevente::on_pushButton_2_clicked()
{
    db.open();
 QString filepath=QFileDialog::getSaveFileName(this, tr("Enregistrer sous ...."), tr(""),tr("folder (*.doc *.txt *.docs *.pdf)"));
 QFile file(filepath);
 if(!file.open(QFile::WriteOnly | QFile::Text)){
     QMessageBox::warning(this, "warning" , " ne peut pas etre sauvegarder  " + file.errorString());
     return;
 }

 QTextStream out(&file);
 QSqlQuery query;

 query.exec("SELECT nom,prix_2,quantite,total,Date from vente");

 QString recherche1;

 while(query.next()){
     recherche1 += "Nom : " + query.value(0).toString() +" ; " + "\t";
     recherche1 += "Prix : " + query.value(1).toString()  + " ; "+ "\t";
     recherche1 += "QT Vendues : " + query.value(2).toString()  + " ;" + "\t\t";
     recherche1 += "Totale : " + query.value(3).toString()+ "\t\t";
     recherche1 += "Date : " + query.value(4).toString() + "\t\n\n";

 }
 QString text;
 out << " \t \t\t MARCHE GERALD , BUSINESS ALBERT EDNA \n\n\n";
  out << " \t \t \t Liste des produits vendues \n\n\n" ;
 out << recherche1 << endl ;
 file.close();

// QString filepatch=QFileDialog::getOpenFileName(this, "open folder");


}


























void listevente::opentabfile(QString filepatch)
{
    QFile file(filepatch);
    QFileInfo filename(filepatch);

    if(!file.open(QFile::QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "warning" , " ne peut pas etre sauvegarder" + file.errorString());
        return;
    }

    QTextStream in(&file);
    QString text= in.readAll();
}

void listevente::currenttextedit()
{

}

