#include "listedepense.h"
#include "ui_listedepense.h"
#include "QMessageBox"
#include"QSqlQuery"
#include<iostream>
#include"QSqlQueryModel"
#include "QFileDialog"
#include"QFile"
#include"QTextStream"
listedepense::listedepense(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listedepense)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT iddepense, motif, quantite,date,compte FROM depense");
    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(quantite) from depense");
if(somme.next()){
 montant= somme.value(0).toString() + " Gourdes" ;
}
ui->montant->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);
   query.clear();

}

listedepense::~listedepense()
{
    delete ui;
}

void listedepense::on_pushButton_clicked()
{


    db.open();
    QSqlQuery recherche;
    QString recherche1;
    QString valeur=ui->nomproduit->text();

    recherche.exec("SELECT  iddepense, motif, quantite,date,compte  from depense where motif='"+valeur+"'");
    if(recherche.next()){
        recherche1 = recherche.value(0).toString();
    }

    if(recherche1.isEmpty()){
        QMessageBox::critical(this,"message"," introuvable  ");
    }else{
        QSqlQuery somme;
        QString montant;

 somme.exec("SELECT SUM(quantite) from depense where motif='"+valeur+"'");
 if(somme.next()){
     montant= somme.value(0).toString() + " gourdes";
 }
 ui->montant->setText(montant);
        QSqlQueryModel * modal =new QSqlQueryModel();

        modal->setQuery(recherche);

        ui->tableView->setModel(modal);
       recherche.clear();

    }

}


void listedepense::on_supprimer_clicked()
{

    db.open();


     QSqlQuery query1,query2;
     QString test;
     QString Iddepense = ui->iddepense->text();
     query2.exec("SELECT iddepense from depense where iddepense='"+Iddepense+"'");
     if(query2.next()){
         test = query2.value(0).toString();
     }
     if(test.isEmpty()){
         QMessageBox::critical(this,"Message", " erreur d'id");
         ui->iddepense->clear();
     }else{

    QSqlQuery query,update,query2,update2,recherche;

    query = QSqlQuery("SELECT montant FROM comptevente");
      recherche.exec("SELECT quantite from depense where iddepense='"+Iddepense+"'");

      query1.exec("DELETE FROM depense WHERE iddepense="+Iddepense);
      int reste=0;
    int RReste;
    QString Reste,restes,plus;
    if(recherche.next()){
        plus= recherche.value(0).toString();
    }
    if(query.next()){
       reste=query.value(0).toInt();
    }

    RReste=reste + plus.toInt() ;
    Reste= QString::number(RReste) ;

 update.exec("UPDATE vente SET somme='"+Reste+"'");
   update2.exec("UPDATE comptevente SET montant='"+Reste+"'");

    QMessageBox::information(this,"Message", " Supprimer avec succes");
    ui->iddepense->clear();
    db.open();
    QString affichage="";


    query.exec("SELECT iddepense, motif, quantite,date,compte FROM depense");

    QSqlQueryModel * modal =new QSqlQueryModel();
    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(quantite) from depense");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}
ui->montant->setText(montant);
    modal->setQuery(query);

    ui->tableView->setModel(modal);
   query.clear();
    query1.clear();

}

}
void listedepense::on_listerdepense_clicked()
{

    db.open();
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT iddepense, motif, quantite,date,compte FROM depense");

    QSqlQueryModel * modal =new QSqlQueryModel();
    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(quantite) from depense");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}
ui->montant->setText(montant);
    modal->setQuery(query);

    ui->tableView->setModel(modal);
   query.clear();

}


void listedepense::on_mois_2_clicked()
{
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

    QString mois = ui->mois->text();
    if(mois.isEmpty()){
        QMessageBox::critical(this,"message","veuiller entrer le mois recherche");
    }else{
        if(!mois.toInt()){
            QMessageBox::critical(this,"message","veuiller entrer le mois en chiffre ");

        }else{
            QSqlQuery recherche,query;

            recherche.exec("SELECT iddepense , motif, quantite,date,compte from depense where mois ='"+mois+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(quantite) from depense where mois ='"+mois+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{
         ui->montant->setText(montant);
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


void listedepense::on_jour_2_clicked()
{

    db.open();

    QString jour = ui->jour->text();
    if(jour.isEmpty()){
        QMessageBox::critical(this,"message","veuiller entrer l annee recherche");
    }else{
        if(!jour.toInt()){
            QMessageBox::critical(this,"message","veuiller entrer l annee en chiffre ");

        }else{
            QSqlQuery recherche,query;

            recherche.exec("SELECT iddepense, motif, quantite,date,compte from depense where jour ='"+jour+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(quantite) from depense where jour ='"+jour+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{
         ui->montant->setText(montant);
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


void listedepense::on_anne_2_clicked()
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

            recherche.exec("SELECT iddepense, motif, quantite,date,compte from depense where anne ='"+anne+"'");
            if(recherche.exec()){
                QSqlQuery somme;
                QString montant;

         somme.exec("SELECT SUM(quantite) from depense where anne ='"+anne+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " gourdes";
         }
         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{
         ui->montant->setText(montant);
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


void listedepense::on_tout_clicked()
{

    db.open();
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT iddepense, motif, quantite,date,compte FROM depense");
    QSqlQuery somme;
    QString montant;

somme.exec("SELECT SUM(quantite) from depense");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}
ui->montant->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView->setModel(modal);
   query.clear();

}


void listedepense::on_enregistrer_clicked()
{
    db.open();
 QString filepath=QFileDialog::getSaveFileName(this, tr("Enregistrer sous ...."), tr(""),tr("folder (*.doc *.txt *.docs *.pdf)"));
 QFile file(filepath);
 if(!file.open(QFile::WriteOnly | QFile::Text)){
     QMessageBox::warning(this, "warning" , " cannot save..  " + file.errorString());
     return;
 }

 QTextStream out(&file);
 QSqlQuery query;

 query.exec("SELECT motif,quantite,Date from depense");

 QString recherche1;

 while(query.next()){
     recherche1 += "Motif : " + query.value(0).toString() +" ; " + "\t";
     recherche1 += "QT depenser : " + query.value(1).toString() +" Gourdes" + " ;" + "\t\t";
     recherche1 += "Date : " + query.value(2).toString()+ "\t\n\n";

 }
 QString text;
 out << " \t \t MARCHE GERALD , BUSINESS ALBERT EDNA \n\n\n";
  out << " \t \t \t Liste des depenses \n\n\n" ;
 out << recherche1 << endl ;
 file.close();

}

