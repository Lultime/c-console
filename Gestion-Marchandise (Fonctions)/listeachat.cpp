#include "listeachat.h"
#include "ui_listeachat.h"
#include "QMessageBox"
#include"QSqlQuery"
#include"QSqlQueryModel"
#include "QFileDialog"
#include"QFile"
#include"QTextStream"

listeachat::listeachat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listeachat)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");


    db.open();
    QString affichage="";
    QSqlQuery query4;


    query4.exec("SELECT idproduit,nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total FROM achat ");

    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(total) from achat");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}
ui->montant->setText(montant);
somme.exec("SELECT SUM(quantite) from achat");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}
ui->quantite->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query4);

    ui->tableView->setModel(modal);
   query4.clear();


}

listeachat::~listeachat()
{
    delete ui;
}

void listeachat::on_pushButton_2_clicked()
{


    db.open();


     QSqlQuery query1,query2;
/*
     QString Idproduit = ui->idproduit->text();
      QString test;
     query2.exec("SELECT idproduit from achat where idproduit='"+Idproduit+"'");
     if(query2.next()){
         test = query2.value(0).toString();
     }
     if(test.isEmpty()){
         QMessageBox::critical(this,"Message", " erreur d'id");
         ui->idproduit->clear();
     }else{
    query1.exec("DELETE FROM achat WHERE idproduit="+Idproduit);

    QMessageBox::information(this,"Message", " Supprimer avec succes");
    ui->idproduit->clear();



    query1.clear();
    db.close();
    }
    */

}



void listeachat::on_listeractivite_clicked()
{


    db.open();

    QSqlQuery query;
  QString date="9/14/2034";
    query.exec("SELECT idproduit,nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total FROM achat ");

    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(total) from achat");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}
ui->montant->setText(montant);
somme.exec("SELECT SUM(quantite) from achat");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}
ui->quantite->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);

   // ui->tableView->clearSelection();

   query.clear();

}


void listeachat::on_pushButton_clicked()
{




    db.open();
    QSqlQuery recherche;
    QString recherche1;
    QString valeur=ui->nomproduit->text();

    recherche.exec("SELECT  idproduit,nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total  from achat where nom='"+valeur+"'");
    if(recherche.next()){
        recherche1 = recherche.value(0).toString();
    }

    if(recherche1.isEmpty()){
        QMessageBox::critical(this,"message"," produit non disponible ");
    }else{
        QSqlQuery somme;
        QString montant;

 somme.exec("SELECT SUM(total) from achat where nom ='"+valeur+"'");
 if(somme.next()){
     montant= somme.value(0).toString() + " gourdes";
 }
 ui->montant->setText(montant);
 somme.exec("SELECT SUM(quantite) from achat where nom ='"+valeur+"'");
 if(somme.next()){
     montant= somme.value(0).toString() + " unite";
 }
 ui->quantite->setText(montant);
        QSqlQueryModel * modal =new QSqlQueryModel();

        modal->setQuery(recherche);

        ui->tableView->setModel(modal);
       recherche.clear();

    }

}


void listeachat::on_pushButton_3_clicked()
{

}


void listeachat::on_anne_2_clicked()
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

            recherche.exec("SELECT idproduit,  nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total from achat where anne ='"+anne+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(total) from achat where anne ='"+anne+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         ui->montant->setText(montant);
         somme.exec("SELECT SUM(quantite) from achat where anne ='"+anne+"'");
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


               // ui->tableView->clearSelection();

               query.clear();
            }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void listeachat::on_jour_2_clicked()
{


    db.open();

    QString jour = ui->jour->text();
    if(jour.isEmpty()){
        QMessageBox::critical(this,"message","veuiller entrer le jour recherche");
    }else{
        if(!jour.toInt()){
            QMessageBox::critical(this,"message","veuiller entrer le jour en chiffre ");

        }else{
            QSqlQuery recherche,query;

            recherche.exec("SELECT idproduit, nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total from achat where jour ='"+jour+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(total) from achat where jour ='"+jour+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         ui->montant->setText(montant);
         somme.exec("SELECT SUM(quantite) from achat where jour ='"+jour+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " unite";
         }
         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{
         ui->montant->setText(montant);
         ui->quantite->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView->setModel(modal);


               // ui->tableView->clearSelection();

               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void listeachat::on_mois_2_clicked()
{

    db.open();

    QString mois = ui->mois->text();
    if(mois.isEmpty()){
        QMessageBox::critical(this,"message","veuiller entrer le mois recherche");
    }else{
        if(!mois.toInt()){
            QMessageBox::critical(this,"message","veuiller entrer le mois en chiffre ");

        }else{
            QSqlQuery recherche,query;

            recherche.exec("SELECT  idproduit, nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total from achat where mois ='"+mois+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(total) from achat where mois ='"+mois+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
    ui->montant->setText(montant);
         somme.exec("SELECT SUM(quantite) from achat where mois ='"+mois+"'");
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


               // ui->tableView->clearSelection();

               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void listeachat::on_tout_clicked()
{


    db.open();

    QSqlQuery query;

    query.exec("SELECT idproduit,nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total  FROM achat ");

    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(total) from achat");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}
ui->montant->setText(montant);
somme.exec("SELECT SUM(quantite) from achat");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}
ui->quantite->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);

    ui->tableView->clearSelection();

   query.clear();

}


void listeachat::on_commandLinkButton_clicked()
{

}


void listeachat::on_enregistrer_clicked()
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

 query.exec("SELECT nom,prix,quantite,total,Date from achat");

 QString recherche1;

 while(query.next()){
     recherche1 += "Nom : " + query.value(0).toString() +" ; " + "\t";
     recherche1 += "Prix : " + query.value(1).toString() +" Gourdes" + " ; "+ "\t";
     recherche1 += "QT : " + query.value(2).toString() +" Unite" + " ;" + "\t\t";
     recherche1 += "Totale : " + query.value(3).toString()+" Gourdes" + "\t\t";
     recherche1 += "Date : " + query.value(4).toString()  + "\t\n\n";


 }
 QString text;
 out << " \t \t MARCHE GERALD , BUSINESS ALBERT EDNA \n\n\n";
  out << " \t \t \t Liste des achats \n\n\n" ;
 out << recherche1 << endl ;
 file.close();

}

