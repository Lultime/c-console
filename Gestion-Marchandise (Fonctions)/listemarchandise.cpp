#include "listemarchandise.h"
#include "ui_listemarchandise.h"
#include"QSqlQueryModel"
#include "QMessageBox"
#include"QSqlQuery"
#include "QFileDialog"
#include"QFile"
#include"QTextStream"

listemarchandise::listemarchandise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listemarchandise)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");


    db.open();


    QSqlQuery deleted;
    int i=0;
      deleted.exec("DELETE FROM marchandise WHERE quantite='"+QString::number(i)+"'");



    QSqlQuery query;


    query.exec("SELECT idproduit,nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total  FROM marchandise");


    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(total) from marchandise");
if(somme.next()){
 montant= somme.value(0).toString() +  " gourdes";
}
ui->montant->setText(montant);
somme.exec("SELECT SUM(quantite) from marchandise");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}
ui->quantite->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);
   query.clear();

}

listemarchandise::~listemarchandise()
{
    delete ui;
}

void listemarchandise::on_pushButton_2_clicked()
{


/*

     QSqlQuery query1,query2;
     QString test;
     QString Idproduit = ui->idproduit->text();
     query2.exec("SELECT idproduit from marchandise where idproduit='"+Idproduit+"'");
     if(query2.next()){
         test = query2.value(0).toString();
     }
     if(test.isEmpty()){
         QMessageBox::critical(this,"Message", " erreur d'id");
         ui->idproduit->clear();
     }else{
    query1.exec("DELETE FROM marchandise WHERE idproduit="+Idproduit);

    QMessageBox::information(this,"Message", " Supprimer avec succes");
    ui->idproduit->clear();

    query1.clear();
    db.close();
}
*/
}
void listemarchandise::on_listerproduit_clicked()
{



    db.open();


    QString affichage="";
    QSqlQuery query;


    query.exec("SELECT idproduit, nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total FROM marchandise");

    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(total) from marchandise");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}
ui->montant->setText(montant);
somme.exec("SELECT SUM(quantite) from marchandise");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}
ui->quantite->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);
   query.clear();

}


void listemarchandise::on_mois_2_clicked()
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

            recherche.exec("SELECT   idproduit,nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total from marchandise where mois ='"+mois+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(total) from marchandise where mois ='"+mois+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         ui->montant->setText(montant);
         somme.exec("SELECT SUM(quantite) from marchandise where mois ='"+mois+"'");
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


void listemarchandise::on_jour_2_clicked()
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

            recherche.exec("SELECT  idproduit, nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total from marchandise where jour ='"+jour+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(total) from marchandise where jour ='"+jour+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         ui->montant->setText(montant);
         somme.exec("SELECT SUM(quantite) from marchandise where jour ='"+jour+"'");
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


              ui->jour->clear();
               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void listemarchandise::on_anne_2_clicked()
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

            recherche.exec("SELECT  idproduit, nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total from marchandise where anne ='"+anne+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(total) from marchandise where anne ='"+anne+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         ui->montant->setText(montant);
         somme.exec("SELECT SUM(quantite) from marchandise where anne ='"+anne+"'");
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


            ui->anne->clear();
               query.clear();
            }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void listemarchandise::on_tout_clicked()
{

    db.open();

    QSqlQuery query;


    query.exec("SELECT idproduit,nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total  FROM marchandise");

    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(total) from marchandise");
if(somme.next()){
 montant= somme.value(0).toString();
}
ui->montant->setText(montant);
somme.exec("SELECT SUM(quantite) from marchandise");

if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}
ui->quantite->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);
   query.clear();

}


void listemarchandise::on_pushButton_clicked()
{
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");


    db.open();
    QSqlQuery recherche;
    QString recherche1;
    QString valeur=ui->nomproduit->text();

    recherche.exec("SELECT idproduit, nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total  from marchandise where nom='"+valeur+"'");
    if(recherche.next()){
        recherche1 = recherche.value(0).toString();
    }

    if(recherche1.isEmpty()){
        QMessageBox::critical(this,"message"," produit non disponible ");
    }else{
        QSqlQuery somme;
        QString montant;

 somme.exec("SELECT SUM(total) from marchandise where nom='"+valeur+"'");
 if(somme.next()){
     montant= somme.value(0).toString() + " gourdes";
 }
 ui->montant->setText(montant);
 somme.exec("SELECT SUM(quantite) from marchandise  where nom='"+valeur+"'");
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


void listemarchandise::on_enregistrer_clicked()
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

 query.exec("SELECT nom,prix,quantite,total,Date from marchandise");

 QString recherche1;

 while(query.next()){
     recherche1 += "Nom : " + query.value(0).toString() +" ; " + "\t";
     recherche1 += "Prix : " + query.value(1).toString() +" Gourdes" + " ; "+ "\t";
     recherche1 += "QT : " + query.value(2).toString() +" Unite" + " ;" + "\t\t";
     recherche1 += "Totale : " + query.value(3).toString() +" Gourdes" + "\t\t";
     recherche1 += "Date : " + query.value(4).toString() + "\t\n\n";

 }

 out << " \t \t MARCHE GERALD , BUSINESS ALBERT EDNA \n\n\n";
  out << " \t \t \t Liste des Marchandises \n\n\n" ;
 out << recherche1 << endl ;
 file.close();

}


void listemarchandise::on_tableView_doubleClicked(const QModelIndex &index)
{

}


void listemarchandise::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    Marchandise =new marchandise(this);
    Marchandise->show();
}

