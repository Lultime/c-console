#include "accueil.h"
#include "ui_accueil.h"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
//#include "utilisateur.h"
//#include "ui_utilisateur.h"
//#include"utilisateur.cpp"
#include "connexion.h"
#include "ui_connexion.h"
#include"QSqlQueryModel"
#include "QFileDialog"
#include"QFile"
#include"QTextStream"

accueil::accueil(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::accueil)
{
    ui->setupUi(this);

    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();
    int INT12=1;
   QString INT= QString::number(INT12);

    QSqlQuery requete,requete2,requete3,requete4,requete1;
    QString verif,add,add2,add3,add1,add4;
    requete.exec("SELECT somme from vente ");

    while(requete.next()){
        add1 = requete.value(0).toString();
    }
    requete4.exec("SELECT SUM(total) from achat ");

    if(requete4.next()){
        add4 = requete4.value(0).toString();
    }

   requete.exec("UPDATE comptevente set  montant='"+add1+"' where id='"+INT+"'");

    int INT13=2;
   QString INT3= QString::number(INT13);
    requete1.exec("UPDATE comptevente set  montant='"+add4+"' where id='"+INT3+"'");
    int Int=1;
    QString Int1=QString::number(Int);
    requete.exec("SELECT email FROM utilisateur where cle='"+Int1+"'");
    if(requete.next()){
        add= requete.value(0).toString();
    }
    requete2.exec("SELECT nom FROM utilisateur where cle='"+Int1+"'");
    if(requete2.next()){
        add2=requete2.value(0).toString();
    }
    requete3.exec("SELECT grade FROM utilisateur where cle='"+Int1+"'");
    if(requete3.next()){
        add3= requete3.value(0).toString();
    }
    //QString Username = ui->username->text();
     ui->grade->setText(add3);
    ui->email->setText(add);
    ui->nom->setText(add2);
    int Int3=0;
    QString Int2=QString::number(Int3);
    requete.exec("update utilisateur set  cle='"+Int2+"' where cle='"+Int1+"'");



//achat
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

   ///////////


   ///
   QString affichage2="";
   QSqlQuery query2;

   query2.exec("SELECT iddepense, motif, quantite,date,compte FROM depense");
   QSqlQuery somme2;
   QString montant2;

somme2.exec("SELECT SUM(quantite) from depense");
if(somme2.next()){
montant2= somme2.value(0).toString() + " Gourdes" ;
}
ui->montant_4->setText(montant2);
   QSqlQueryModel * modal2 =new QSqlQueryModel();

   modal2->setQuery(query2);

   ui->tableView_4->setModel(modal2);
  query2.clear();
//ui->stackedWidget->setCurrentWidget(ui->page_5);
///////
///
///
///
QString affichage3="";
QSqlQuery query3;

query3.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente");
QSqlQuery somme3;
QString montant3;

somme3.exec("SELECT SUM(total) from vente");
if(somme3.next()){
montant3= somme3.value(0).toString() + " gourdes";
}
ui->montant_3->setText(montant3);
somme3.exec("SELECT SUM( quantite) from vente");
if(somme3.next()){
montant3= somme3.value(0).toString() + " unite";
}

ui->quantite_3->setText(montant3);
QSqlQueryModel * modal3 =new QSqlQueryModel();

modal3->setQuery(query3);

ui->tableView_3->setModel(modal3);

query3.clear();
//ui->stackedWidget->setCurrentWidget(ui->page_4);
////
///

QSqlQuery deleted;
int i=0;
  deleted.exec("DELETE FROM marchandise WHERE quantite='"+QString::number(i)+"'");



QSqlQuery query5;


query5.exec("SELECT idproduit,nom, quantite, prix , tca, fournisseur,Categorie, Date,remarque , total  FROM marchandise");


QSqlQuery somme4;
QString montant4;

somme4.exec("SELECT SUM(total) from marchandise");
if(somme4.next()){
montant4= somme4.value(0).toString() +  " gourdes";
}
ui->montant_2->setText(montant4);
somme4.exec("SELECT SUM(quantite) from marchandise");
if(somme4.next()){
montant4= somme4.value(0).toString() + " unite";
}
ui->quantite_2->setText(montant4);
QSqlQueryModel * modal4 =new QSqlQueryModel();

modal4->setQuery(query5);

ui->tableView_2->setModel(modal4);
query5.clear();

//ui->stackedWidget->setCurrentWidget(ui->page_3);

}

accueil::~accueil()
{
    delete ui;
}


void accueil::on_actionEnregistrer_une_activite_triggered()
{
    Achat= new achat(this);
    Achat->show();

}





void accueil::on_actionNouvelle_donnee_triggered()
{
    Vente= new vente(this);
    Vente->show();

}


void accueil::on_actionenregistrer_une_depense_triggered()
{
    Depense= new depense1(this);
    Depense->show();
}


void accueil::on_actionnew_user_triggered()
{
    db.open();
    QSqlQuery user3;
    QString verifier3;
    user3.exec("SELECT * FROM utilisateur");
if(user3.exec()){
    if(user3.next()){
        verifier3 =user3.value(0).toString();
    }
    if(!verifier3.isEmpty()){
    authen * Authen= new authen;
    Authen->show();
    }else{
        Utilisateur=new utilisateur;
        Utilisateur->show();
    }
}else{
   QMessageBox::warning(this,"accueil", "erreur d acces" );
}


}










void accueil::on_actionexite_triggered()
{
    QMessageBox::StandardButton reply= QMessageBox::question(this,"accueil", "voulez vous quitter l aplication ?",
                           QMessageBox::Yes | QMessageBox::No );
                          if(reply == QMessageBox::Yes){
                                close();
                                                             }
            else {

 }
}





void accueil::on_activite_clicked()
{
    Achat= new achat();
    Achat->show();

}


void accueil::on_activite_2_clicked()
{
    Depense= new depense1();
    Depense->show();

}


void accueil::on_offrande_clicked()
{
    Vente= new vente();
    Vente->show();


}


void accueil::on_login_clicked()
{
    Connexion= new connexion();
    Connexion->show();
    close();

}


void accueil::on_logout_clicked()
{
    Connexion= new connexion();
    Connexion->show();
    close();
}


void accueil::on_actionliste_des_depenses_triggered()
{

   Listedepense= new listedepense();
   Listedepense->show();

}


void accueil::on_listedepense_clicked()
{

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
ui->montant_4->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView_4->setModel(modal);
   query.clear();
ui->stackedWidget->setCurrentWidget(ui->page_5);

}


void accueil::on_actionliste_des_activites_triggered()
{
    Listeachat= new listeachat();
    Listeachat->show();
}


void accueil::on_actionliste_des_donnees_triggered()
{
    Listevente= new listevente();
    Listevente->show();
}


void accueil::on_listeactivite_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}


void accueil::on_listefond_clicked()
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
 ui->montant_3->setText(montant);
somme.exec("SELECT SUM( quantite) from vente");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}

 ui->quantite_3->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView_3->setModel(modal);

   query.clear();
ui->stackedWidget->setCurrentWidget(ui->page_4);
}


void accueil::on_events_clicked()
{



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
ui->montant_2->setText(montant);
somme.exec("SELECT SUM(quantite) from marchandise");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}
ui->quantite_2->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView_2->setModel(modal);
   query.clear();

    ui->stackedWidget->setCurrentWidget(ui->page_3);
}


void accueil::on_actionsuprimer_une_activite_triggered()
{
    Listeachat= new listeachat();
    Listeachat->show();
}


void accueil::on_actionmodifier_une_activite_triggered()
{
    db.open();
    QSqlQuery user;
    QString verifier;
    user.exec("SELECT * FROM utilisateur");
if(user.exec()){
    if(user.next()){
        verifier =user.value(0).toString();
    }
    if(!verifier.isEmpty()){
    Authen2 = new authen2();
    Authen2->show();
    }else{
        Modifierachat =new modifierachat();
        Modifierachat->show();
    }
}else{
    QMessageBox::warning(this,"accueil", "erreur d acces" );
}


}

void accueil::on_actionmodifier_donnee_triggered()
{
    db.open();
    QSqlQuery user1;
    QString verifier1;
    user1.exec("SELECT * FROM utilisateur");
if(user1.exec()){
    if(user1.next()){
        verifier1 =user1.value(0).toString();
    }
    if(!verifier1.isEmpty()){
    Authen1  = new authen1();
    Authen1->show();
    }else{
        Modifiervente = new modifiervente();
        Modifiervente->show();
    }
}else{
    QMessageBox::warning(this,"accueil", "erreur d acces" );
}

}


void accueil::on_actionsuprimer_modifier_triggered()
{
    db.open();
    QSqlQuery user2;
    QString verifier2;
    user2.exec("SELECT * FROM utilisateur");
if(user2.exec()){
    if(user2.next()){
        verifier2 =user2.value(0).toString();
    }
    if(!verifier2.isEmpty()){
    Authen1  = new authen1();
    Authen1->show();
    }else{
        modifierdepense * modifier = new modifierdepense ();
        modifier->show();
    }
}else{
    QMessageBox::warning(this,"accueil", "erreur d acces" );
}

}


void accueil::on_actionSupprimer_triggered()
{
    Listedepense= new listedepense();
    Listedepense->show();

}


void accueil::on_actionEnregistrer_marchandise_initial_triggered()
{
    Marchandise= new marchandise();
    Marchandise->show();
}


void accueil::on_actionMarchandise_triggered()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}


void accueil::on_actionmodifier_triggered()
{

}

void accueil::on_actionCompte_achat_triggered()
{
    Compteachat= new compteachat();
    Compteachat->show();
}


void accueil::on_actionCompte_vente_triggered()
{
    Comptevente= new comptevente();
    Comptevente->show();
}


void accueil::on_actionCompte_depense_triggered()
{
    Comptedepense=new comptedepense();
    Comptedepense->show();
}


void accueil::on_actionCompte_marchandise_triggered()
{
    Comptemarchandise= new comptemarchandise();
    Comptemarchandise->show();
}


void accueil::on_pushButton_clicked()
{
ui->stackedWidget->setCurrentWidget(ui->page);
}


void accueil::on_nomproduit_textChanged(const QString &arg1)
{

}


void accueil::on_actionRediger_une_vente_triggered()
{
    Same = new same();
    Same->show();
}


void accueil::on_fichedevente_clicked()
{
    Same = new same();
    Same->show();
}


void accueil::on_fichededepense_clicked()
{
Redigerrapportdepense = new redigerrapportdepense();
        Redigerrapportdepense->show();
}


void accueil::on_fichedachat_clicked()
{
    Redigerrapportachat = new redigerrapportachat();
            Redigerrapportachat->show();
    }



void accueil::on_actionopen_Folder_triggered()
{
    QUrl dirpatch= QFileDialog::getExistingDirectory(this,"Open Folder", "/",QFileDialog::ShowDirsOnly);
   // dirmodel=
}


void accueil::on_actionUtilisateurs_triggered()
{
Listeuser= new listeuser();
Listeuser->show();
}


void accueil::on_mois_4_clicked()
{


    db.open();

    QString mois = ui->mois_4->text();
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


void accueil::on_jour_2_clicked()
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


void accueil::on_anne_2_clicked()
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


void accueil::on_tout_clicked()
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


void accueil::on_listeractivite_clicked()
{

}


void accueil::on_enregistrer_clicked()
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


void accueil::on_pushButton_2_clicked()
{



    db.open();
    QSqlQuery recherche;
    QString recherche1;
    QString valeur=ui->nomproduit_2->text();

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


void accueil::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}


void accueil::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}


void accueil::on_mois_8_clicked()
{
    db.open();

    QString mois = ui->mois_8->text();
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
         ui->montant_2->setText(montant);
         somme.exec("SELECT SUM(quantite) from marchandise where mois ='"+mois+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " unite";
         }
         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{
          ui->quantite_2->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView_2->setModel(modal);


               ui->mois_9->clear();

               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void accueil::on_jour_6_clicked()
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
         ui->montant_2->setText(montant);
         somme.exec("SELECT SUM(quantite) from marchandise where jour ='"+jour+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " unite";
         }
         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{

         ui->quantite_2->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView_2->setModel(modal);


              ui->jour->clear();
               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void accueil::on_anne_6_clicked()
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
         ui->montant_2->setText(montant);
         somme.exec("SELECT SUM(quantite) from marchandise where anne ='"+anne+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " unite";
         }
         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{

         ui->quantite_2->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView_2->setModel(modal);


            ui->anne->clear();
               query.clear();
            }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void accueil::on_tout_2_clicked()
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
ui->montant_2->setText(montant);
somme.exec("SELECT SUM(quantite) from marchandise");

if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}
ui->quantite_2->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView_2->setModel(modal);
   query.clear();

}


void accueil::on_listeractivite_2_clicked()
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
ui->montant_2->setText(montant);
somme.exec("SELECT SUM(quantite) from marchandise");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}
ui->quantite_2->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView_2->setModel(modal);
   query.clear();

}


void accueil::on_enregistrer_2_clicked()
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


void accueil::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
}


void accueil::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);

}


void accueil::on_mois_10_clicked()
{
    db.open();

    QString mois = ui->mois_9->text();
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
          ui->montant_3->setText(montant);
         somme.exec("SELECT SUM(quantite) from vente where mois ='"+mois+"'");
         if(somme.next()){
             montant= somme.value(0).toString() + " unite";
         }

         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{

          ui->quantite_3->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView_3->setModel(modal);


                ui->mois_9->clear();


               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }

}


void accueil::on_jour_8_clicked()
{
    db.open();

    QString jour = ui->jour_7->text();
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
         ui->montant_3->setText(montant);

         somme.exec("SELECT SUM(quantite) from vente where jour ='"+jour+"'");
         if(somme.next()){
             montant= somme.value(0).toString()+ " unite";
         }

         if(montant.isEmpty()){
             QMessageBox::critical(this,"message","pas de resultats");

         }else{
          ui->quantite_3->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView_3->setModel(modal);


                ui->jour_7->clear();


               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }
}


void accueil::on_anne_8_clicked()
{
    db.open();

    QString anne = ui->anne_7->text();
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
         ui->montant_3->setText(montant);

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

                ui->tableView_3->setModel(modal);


             ui->anne_7->clear();
               query.clear();
            }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }
}


void accueil::on_tout_3_clicked()
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
ui->quantite_3->setText(montant);
    modal->setQuery(query);

    ui->tableView_3->setModel(modal);

   query.clear();
}


void accueil::on_pushButton_7_clicked()
{
    db.open();
    QSqlQuery recherche;
    QString recherche1;
    QString valeur=ui->nomproduit_4->text();

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
 ui->montant_3->setText(montant);
 somme.exec("SELECT SUM(quantite) from vente where nom ='"+valeur+"'");
 if(somme.next()){
     montant= somme.value(0).toString() + " unite";
 }
 ui->quantite_3->setText(montant);

        QSqlQueryModel * modal =new QSqlQueryModel();

        modal->setQuery(recherche);

        ui->tableView_3->setModel(modal);
       recherche.clear();

    }

}


void accueil::on_enregistrer_3_clicked()
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


void accueil::on_listeractivite_3_clicked()
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


void accueil::on_mois_14_clicked()
{
    db.open();

    QString mois = ui->mois_13->text();
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
         ui->montant_4->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView_4->setModel(modal);


               ui->mois_13->clear();

               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }
}


void accueil::on_jour_12_clicked()
{
    db.open();

    QString jour = ui->jour_11->text();
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
         ui->montant_4->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView_4->setModel(modal);


                ui->jour_11->clear();

               query.clear();
         }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }
}


void accueil::on_anne_12_clicked()
{
    db.open();

    QString anne = ui->anne_11->text();
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
         ui->montant_4->setText(montant);
                QSqlQueryModel * modal =new QSqlQueryModel();

                modal->setQuery(recherche);

                ui->tableView_4->setModel(modal);


                ui->anne_11->clear();

               query.clear();
            }
            }else{
                QMessageBox::critical(this,"message","echec ");

            }
        }
    }
}


void accueil::on_tout_4_clicked()
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
ui->montant_4->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView_4->setModel(modal);
   query.clear();
}


void accueil::on_listeractivite_4_clicked()
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
ui->montant_4->setText(montant);
    modal->setQuery(query);

    ui->tableView_4->setModel(modal);
   query.clear();

}


void accueil::on_enregistrer_4_clicked()
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


void accueil::on_pushButton_10_clicked()
{
    db.open();
    QSqlQuery recherche;
    QString recherche1;
    QString valeur=ui->nomproduit_5->text();

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
 ui->montant_4->setText(montant);
        QSqlQueryModel * modal =new QSqlQueryModel();

        modal->setQuery(recherche);

        ui->tableView_4->setModel(modal);
       recherche.clear();

    }

}


void accueil::on_pushButton_9_clicked()
{
    ui->stackedWidget_2->setCurrentWidget(ui->page_7);
}


void accueil::on_supprimer_clicked()
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
    int INT12=1;
   QString INT= QString::number(INT12);

    query = QSqlQuery("SELECT montant FROM comptevente  where id='"+INT+"'");

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


   update2.exec("UPDATE comptevente SET montant='"+Reste+"' where id='"+INT+"'");

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
ui->montant_4->setText(montant);
    modal->setQuery(query);

    ui->tableView_4->setModel(modal);
   query.clear();
    query1.clear();

}

}


void accueil::on_supprimer_3_clicked()
{
    ui->stackedWidget_3->setCurrentWidget(ui->page_9);
}


void accueil::on_supprimer_2_clicked()
{
    db.open();


     QSqlQuery query1,query2,query3,query4,query5,query6,query7,query8,prix1,tca1,query9,query10,query11,query12;
     QString test,Idproduit;
     QString Idcaisse = ui->idcaisse_2->text();
     query2.exec("SELECT idvente from vente where idvente='"+Idcaisse+"'");
     if(query2.next()){
         test = query2.value(0).toString();
     }
     if(test.isEmpty()){
         QMessageBox::critical(this,"Message", " erreur d'id");
         ui->idcaisse_2->clear();
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
         query12.exec("SELECT idproduit from vente where  idvente='"+Idcaisse+"'");
         if(query12.next()){
             Idproduit= query12.value(0).toString();
         }
      query5.exec("SELECT quantite from marchandise where nom='"+nomproduit+"' and idproduit='"+Idproduit+"'");
         if(query5.next()){
             quantite2 = query5.value(0).toString();
         }
         quantiteinit= quantite2.toInt() + quantite.toInt() ;
         quantiteinit1 =QString::number(quantiteinit) + " unite";
        query7.exec("SELECT total from marchandise where nom='"+nomproduit+"' and idproduit='"+Idproduit+"'");
        if(query7.next()){
            total = query7.value(0).toString();
        }
        prix1.exec("SELECT prix from marchandise WHERE nom='"+nomproduit+"' and idproduit='"+Idproduit+"'");
      if(prix1.next()){
          prix= prix1.value(0).toString();
      }


      tca1.exec("SELECT tca from marchandise WHERE nom='"+nomproduit+"'and idproduit='"+Idproduit+"'");
    if(tca1.next()){
        tca= tca1.value(0).toString();
    }

    int Totale= quantiteinit* prix.toInt() + tca.toInt() ;
    total1=QString::number(Totale) + "Gourdes";

       query4.exec("UPDATE marchandise set quantite='"+quantiteinit1+"' , total ='"+ total1+"'  WHERE nom='"+nomproduit+"' and idproduit='"+Idproduit+"'");
       int INT12=1;
      QString INT= QString::number(INT12);

       query8.exec("SELECT montant from comptevente where id='"+INT+"'");
         if(query8.next()){
             montantfinal= query8.value(0).toString();
         }
         query10.exec("SELECT total from vente  WHERE nom='"+nomproduit+"' and idproduit='"+Idproduit+"'");
         if(query10.next()){
            montant1= query10.value(0).toString();
         }
         int montant2= montantfinal.toInt() - montant1.toInt();
         QString montant3=QString::number(montant2) + " Gourdes";


         query9.exec("UPDATE comptevente set montant='"+ montant3+"' where id='"+INT+"'");

   //  query11.exec("SELECT SUM(total) from marchandise ");
   //  if(query11.next()){
  //       sum= query11.value(0).toString();
  //   }
    // query12.exec("update
    query1.exec("DELETE FROM vente WHERE idvente="+Idcaisse);

    QMessageBox::information(this,"Message", " Supprimer avec succes");
    ui->idcaisse_2->clear();
    db.open();
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT idvente,nom,Prix,prix_2,categorie,remarque,quantite,date,total from vente");
    QSqlQuery somme;


somme.exec("SELECT SUM(total) from vente");
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";

}
 ui->montant_3->setText(montant);
somme.exec("SELECT SUM( quantite) from vente");
if(somme.next()){
 montant= somme.value(0).toString() + " unite";
}

 ui->quantite_3->setText(montant);
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(query);

    ui->tableView_3->setModel(modal);

   query.clear();
    query1.clear();

}
}


void accueil::on_pushButton_5_clicked()
{
    db.open();
    QSqlQuery recherche;
    QString recherche1;
    QString valeur=ui->nomproduit_3->text();

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
 ui->montant_2->setText(montant);
 somme.exec("SELECT SUM(quantite) from marchandise  where nom='"+valeur+"'");
 if(somme.next()){
  montant= somme.value(0).toString() + " unite";
 }
 ui->quantite_2->setText(montant);
        QSqlQueryModel * modal =new QSqlQueryModel();

        modal->setQuery(recherche);

        ui->tableView_2->setModel(modal);
       recherche.clear();

    }
}


void accueil::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}


void accueil::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);

}


void accueil::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);

}


void accueil::on_tableView_3_activated(const QModelIndex &index)
{
    db.open();

    QSqlQuery select,update,id;
    QString valeur,id1;

    QString val=ui->tableView_3->model()->data(index).toString();
    QSqlQuery user2;
    QString verifier2;
    user2.exec("SELECT * FROM utilisateur");
if(user2.exec()){
    if(user2.next()){
        verifier2 =user2.value(0).toString();
    }
    if(!verifier2.isEmpty()){

    int INT=1;
    valeur=QString::number(INT);
     update.exec("UPDATE vente set cle='"+valeur+"' where idvente ='"+val+"'");

     Authen1  = new authen1();
     Authen1->show();
    }else{

   Modifiervente =new modifiervente();
    Modifiervente->show();
}


db.close();

}
}

void accueil::on_toolButton_triggered(QAction *arg1)
{

}


void accueil::on_tableView_5_activated(const QModelIndex &index)
{

}


void accueil::on_tableView_2_activated(const QModelIndex &index)
{
    db.open();

    QSqlQuery select,update,id;
    QString valeur,id1;

    QString val=ui->tableView_2->model()->data(index).toString();
    QSqlQuery user2;
    QString verifier2;
    user2.exec("SELECT * FROM utilisateur");
if(user2.exec()){
    if(user2.next()){
        verifier2 =user2.value(0).toString();
    }
    if(!verifier2.isEmpty()){
        int INT=1;
        valeur=QString::number(INT);
         update.exec("UPDATE marchandise set cle='"+valeur+"' where idproduit ='"+val+"'");
    Authen1  = new authen1();
    Authen1->show();
    }else{

   Modifiermarchandise =new modifiermarchandise();
    Modifiermarchandise->show();
}
    db.close();
}
}

void accueil::on_actionActif_triggered()
{
Actif =new actif();
Actif->show();
}


void accueil::on_actionBenefice_sur_vente_triggered()
{
  Benefice=new benefice();
Benefice->show();
}


void accueil::on_supprimer_5_clicked()
{
    QString verifier;
    QSqlQuery verifier1;
    QString idachat=ui->idcaisse_3->text();

    verifier1.exec("SELECT idachat from achat where idachat='"+idachat+"'");
    if(verifier1.next()){
        verifier=verifier1.value(0).toInt();
    }

    if(!verifier.isEmpty()){

        verifier1.exec("DELETE from achat where idachat='"+idachat+"'");

        verifier1.exec("DELETE from marchandise where idachat='"+idachat+"'");


    }else{
        QMessageBox::critical(this, "erreur", "id achat introuvable");
    }


}

