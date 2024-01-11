#include "fichevente.h"
#include "ui_fichevente.h"
#include"QSqlQuery"
#include"QMessageBox"
#include"QDateTime"
#include"QPainter"
#include"QFileDialog"
#include"QtDebug"
#include"QSqlQueryModel"


fichevente::fichevente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fichevente)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();



    int Int=1;
    QString Int1=QString::number(Int);
    QString affichage="";
    QSqlQuery query;

    query.exec("SELECT nom,prix_2,quantite,total from vente"); //where cle='"+Int1+"'");
    QSqlQuery somme,Delete,Date;
    QString montant,Date2,titres;

somme.exec("SELECT SUM(total) from vente ");// where cle='"+Int1+"'");
Date.exec("SELECT Date from vente"); //where cle='"+Int1+"'");
if(Date.next()){
    Date2=Date.value(0).toString();
}
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}

 ui->montant->setText(montant);
ui->Date->setText(Date2);
 QSqlQueryModel * modal =new QSqlQueryModel();

 modal->setQuery(query);

 ui->tableView->setModel(modal);

 int Int0=0;
 QString Int2=QString::number(Int0);
Delete.exec("UPDATE vente set cle='"+Int2+"' where cle='"+Int1+"'");
query.clear();

}

fichevente::~fichevente()
{
    delete ui;
}

void fichevente::on_pushButton_clicked()
{
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

    // ne pas use
}


void fichevente::on_print_clicked()
{
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

    int Int=1;
    QString Int1=QString::number(Int);

 // titre = new QTextEdit;
    text= new QTextEdit;
    //titree=new QTextEdit;
    //datee=new QTextEdit;
    //total=new QTextEdit;
     // line=new QLineEdit;
  //  table = new QTableView;
    QString texte;
    QString nom;
    texte="<!DOCTYPE html> <html>"
         "<body> "
         "<h2> Bjr c est mon premier essaie</h2>"
            "<?php echo\"ici du php\"; ?>"
         "</body>"
         "</html>";
    QSqlQuery query;
    QString Date2,titres,Date3;

    query.exec("SELECT nom,prix_2,quantite,total from vente"); //where cle='"+Int1+"'");

    //titres +="Nom  \t    prix    \t       quantite      \t    quantite   \t  total  ";
    titres="Albert";
    while(query.next()){
        Date3 +=query.value(0).toString() + "\t ";
        Date3 +=query.value(1).toString() + "\t ";
        Date3 +=query.value(2).toString() + "\t ";
        Date3 +=query.value(3).toString() + "\t ";


    }
    QSqlQuery somme,Delete,Date;
    QString montant;

somme.exec("SELECT SUM(total) from vente");// where cle='"+Int1+"'");
Date.exec("SELECT Date from vente ");//where cle='"+Int1+"'");
if(Date.next()){
    Date2=Date.value(0).toString();
}
if(somme.next()){
 montant= somme.value(0).toString() + " gourdes";
}

QSqlQueryModel * modal =new QSqlQueryModel();

modal->setQuery(query);
  //  titree->setText(titres);
   //  table->setModel(modal);
   text->setText(Date3);
  //titre->setHtml(texte);

  // datee->setText(Date2);
  // total->setText(montant);

 //line->setText(Date2);
    QPrinter printe;
    printe.setOrientation(QPrinter::Portrait);

    QPrintPreviewDialog dialog(&printe,this);

    connect(&dialog, SIGNAL(paintRequested(QPrinter *)),this,SLOT(print(QPrinter*)));
   dialog.showMaximized();
   dialog.exec();


}


void fichevente::on_save_clicked()
{
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

}

void fichevente::print(QPrinter * printer){
   // titree->print(printer);
    text->print(printer);
    //titre->print(printer);


    /*
    text->print(printer);
    titree->print(printer);
    datee->print(printer);
    total->print(printer);
    */
}



void fichevente::print2(QPrinter * printer2)

{
    titre->print(printer2);
}
