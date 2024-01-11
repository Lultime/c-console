#include "test2.h"
#include "ui_test2.h"
#include"QSqlQuery"
#include"QMessageBox"
#include"QDateTime"
#include"QPainter"
#include"QFileDialog"
#include"QtDebug"
#include"QSqlQueryModel"
#include"QSaveFile"
#include"QMenu"

test2::test2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test2)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();
     QSqlQuery insert,update,update2,query,prix1,tca1;

     int reste=0;
     int RReste;
     QString Reste,prix,tca;
    QString Nomproduit="jeux montre, col,plume";
    QString Idproduit="101";
    QString prix_vente_variation="300";
    prix1.exec("SELECT prix from marchandise WHERE nom='"+Nomproduit+"' and idproduit='"+Idproduit+"'");
  if(prix1.next()){
      prix= prix1.value(0).toString();
  }


  tca1.exec("SELECT tca from marchandise WHERE nom='"+Nomproduit+"' and idproduit='"+Idproduit+"'");
if(tca1.next()){
    tca= tca1.value(0).toString() ;
}

QString  Quantite="3";




     int Totale1=Quantite.toInt() * prix_vente_variation.toInt() ;

    int Totale2= Totale1 - (Quantite.toInt() * prix.toInt() + tca.toInt());

    QString Totale3=QString::number(Totale2);
    ui->lineEdit_2->setText(Totale3);


}

test2::~test2()
{
    delete ui;
}

void test2::on_parcourir_clicked()
{
    db.open();
    QString Nomproduit=ui->nomproduit->text();
    QSqlQuery insert2,insert,verifier,idverifier;
    QString verifier1,verifierid,newid;
    verifier.exec("SELECT nom from marchandise where nom='"+Nomproduit+"'");
    if(verifier.next()){
        verifier1 = verifier.value(0).toString();
    }
    idverifier.exec("SELECT idproduit from marchandise where nom='"+Nomproduit+"'");
    if(idverifier.next()){
        verifierid= idverifier.value(0).toString();
    }

    QSqlQueryModel * modal=new QSqlQueryModel();

    ui->tableView->setModel(modal);
        foreach(verifier,produit){
            if(verifier.value(1).toString() == Nomproduit){
               produit.append(verifier);
            }
       //     QString tablo  = produit;
         //   ui->textEdit->setText();

            menu=new QMenuBar;
            menu->setWindowTitle("salut");
          //  layout->addWidget(menu);

        }
}

void test2::textEditChanged()
{

}

