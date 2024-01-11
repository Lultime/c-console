#include "test.h"
#include "ui_test.h"
#include"QSqlQuery"
#include"QMessageBox"
#include"QDateTime"
#include"QPainter"
#include"QFileDialog"
#include"QtDebug"
#include"QSqlQueryModel"
#include"QSaveFile"
#
test::test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();



    QMap<QString, int> map;

    foreach (const QString &str, map.keys())
        qDebug() << str << ':' << map.value(str);





/*
    ui->stackedWidget->setCurrentWidget(ui->page);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

    QSqlQuery recherche;
    QString recherche1;
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

    // ui->montant->setText(montant);
  //  ui->Date->setText(Date2);
     QSqlQueryModel * modal =new QSqlQueryModel();

     modal->setQuery(query);

  //   ui->tableView->setModel(modal);

     int Int0=0;
     QString Int2=QString::number(Int0);
    Delete.exec("UPDATE vente set cle='"+Int2+"' where cle='"+Int1+"'");
    query.clear();





    db.close();
    */
}

test::~test()
{
    delete ui;
}

void test::on_pushButton_clicked()
{

   // ui->stackedWidget->setCurrentWidget(ui->page_2);


/*
//QString number=ui->number->text();
//QString string=ui->text->text();
// ui->text->setVisible(false);
 //ui->number->setVisible(false);
 //ui->dateEdit->setVisible(false);
 //ui->label_2->setVisible(false);
   QString Anne =ui->anne->text();
   QString mois=ui->mois->text();
   QString Jour=ui->jour->text();
   QString Date= Anne + "/" + mois +"/" + Jour;
   db =QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("C:/marchandise/marchandise.sqlite");
   db.open();

   QSqlQuery recherche;
   QString recherche1;

   recherche.exec("SELECT * from achat ");
   if(recherche.next()){
       recherche1= recherche.value(0).toString()
   }
   QSqlQueryModel * modal =new QSqlQueryModel();

   modal->setQuery(recherche);

   ui->tableView->setModel(modal);
   ui->tableView->setVisible(false);



   db.close();









    db.close();
    */
}



Myclass::Myclass(QWidget * parent):QDialog(parent){
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
   db.open();
   QSqlQuery recherche;
   QString recherche1;
   button= new QPushButton;

   recherche.exec("SELECT nom from marchandise");
if(recherche.next()){
       recherche1 += recherche.value(0).toString() + "\n" + button->text() ;
       recherche1 += recherche.value(1).toString() + "\n" + button->text();
       recherche1 += recherche.value(2).toString() + "\n" + button->text();
       recherche1 += recherche.value(3).toString() + "\n" ;
       recherche1 += recherche.value(4).toString() + "\n";
       recherche1 += recherche.value(5).toString() + "\n";
       recherche1 += recherche.value(6).toString() + "\n";
   }

    setWindowTitle("Title");
    choix= new QComboBox;
    box = new QSpinBox;
    Text =new QTextEdit;
    layout = new QHBoxLayout;
    line=new QLineEdit;
    line->setText(recherche1);

    choix->addItem("First");
    choix->addItem("Second");
    choix->addItem("third");
    button->setText("Clic me");
     line->setGeometry(100,300,600,800);
     line->maximumHeight();

    layout->addWidget(box);
    layout->addWidget(Text);
    layout->addWidget(choix);
    layout->addWidget(button);
    layout->addWidget(line);
    setLayout(layout);

    QObject::connect(button, SIGNAL(clicked()), this , SLOT(writefile()));
}

void Myclass::writefile()
{
 QString fname="C:\\Users\\HP\\Desktop\\QT\\out4.docx";
 QFile file(fname);
 if(file.open(QIODevice::WriteOnly  | QIODevice::Text)){
    QTextStream stream(&file);
    QString textfromspin=QString::number(box->value());
    QString textfrombox=Text->toPlainText();
    QString textfromcombo=choix->currentText();

    stream << " SPinner value :" << textfromspin << endl;
    stream << " combo value :" << textfromcombo << endl;
    stream << " Box value :" << textfrombox << endl;

 }

 file.close();


 /*
// QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
            //                 "/home/jana/untitled.png",
                 //            tr("Images (*.png *.xpm *.jpg)"));


 //
 QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("PDF files"),
                                                 "C:/", "PDF (*.pdf) ;; JPG (*.jpg) ;; PNG (*.png)");

 QFileInfo file(filePath);
 QString fileName= file.fileName();

 if(QFile::copy(filePath, ":/PDF/PDF/"+fileName))
     qDebug() << "success";
 else
     qDebug() << "FAILED TO LOAD TO -> :/PDF/PDF/"+fileName;
     QFileDialog::getOpenFileNames(this, tr("Save File"));
     */

}
void test::on_pushButton_2_clicked()
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
        foreach(verifier,produit){
            if(verifier.value(1).toString() == Nomproduit){
                produit.append(verifier);
            }
        }
    //ui->list->setText(verifier);

   // ui->stackedWidget->setCurrentWidget(ui->page);

    /*
   // QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
               //                 "/home/jana/untitled.png",
                    //            tr("Images (*.png *.xpm *.jpg)"));


    //
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("PDF files"),
                                                    "C:/", "PDF (*.pdf) ;; JPG (*.jpg) ;; PNG (*.png)");

    QFileInfo file(filePath);
    QString fileName= file.fileName();

    if(QFile::copy(filePath, ":/PDF/PDF/"+fileName))
        qDebug() << "success";
    else
        qDebug() << "FAILED TO LOAD TO -> :/PDF/PDF/"+fileName;
        QFileDialog::getOpenFileNames(this, tr("Save File"));
        */
}




void test::on_lineEdit_textChanged(const QString &arg1)
{
    /*
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

    QSqlQuery recherche;
    QString recherche1;

    recherche.exec("SELECT * from achat ");
    if(recherche.next()){
        recherche1 += recherche.value(0).toString();
        recherche1 += recherche.value(1).toString();
        recherche1 += recherche.value(2).toString();
        recherche1 += recherche.value(3).toString();
        recherche1 += recherche.value(4).toString();
        recherche1 += recherche.value(5).toString();
        recherche1 += recherche.value(6).toString();
    }
    QSqlQueryModel * modal =new QSqlQueryModel();

    modal->setQuery(recherche);

    ui->tableView->setModel(modal);
    ui->tableView->setVisible(false);
    if(arg1 == recherche.value(0).toString() || arg1 == recherche.value(1).toString() || arg1 == recherche.value(2).toString() || arg1 == recherche.value(3).toString() || arg1 == recherche.value(4).toString() || arg1 == recherche.value(5).toString() || arg1 == recherche.value(6).toString()   ){

        ui->tableView->setVisible(true);
    }


    db.close();
    */
}


void test::on_print_clicked()
{
/*
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

   // text = new QTextEdit;
    //table = new QTableView;
    doc= new QTextDocument;
    QString texte;
    QString nom;
    texte="<!DOCTYPE html> <html>"
         "<body> "
         "<h2> Bjr c est mon premier essaie</h2>"
            "<?php echo\"ici du php\"; ?>"
         "</body>"
         "</html>";
  nom="ALBERTTTTTTTTTTT";








  int Int=1;
  QString Int1=QString::number(Int);
  QString affichage="";
  QSqlQuery query;

  query.exec("SELECT nom,prix_2,quantite,total from vente");// where cle='"+Int1+"'");
  QSqlQuery somme,Delete,Date;
  QString montant,Date2;
while(query.next()){
    Date2 +=query.value(0).toString() + "\t ";
    Date2 +=query.value(1).toString() + "\t ";
    Date2 +=query.value(2).toString() + "\t ";
    Date2 +=query.value(3).toString() + "\t ";


}




somme.exec("SELECT SUM(total) from vente where cle='"+Int1+"'");
Date.exec("SELECT Date from vente where cle='"+Int1+"'");
if(Date.next()){
  Date2=Date.value(0).toString();
}
if(somme.next()){
montant= somme.value(0).toString() + " gourdes";
}


QSqlQueryModel * modal =new QSqlQueryModel();

modal->setQuery(query);

//ui->tableView->setModel(modal);

  //table->setModel(modal);

   // text->setText(Date2);
   // text->setHtml(texte);
   doc->setPlainText(Date2);
    int Int0=0;
    QString Int2=QString::number(Int0);
    Delete.exec("UPDATE vente set cle='"+Int2+"' where cle='"+Int1+"'");





    QPrinter printe;
    printe.setOrientation(QPrinter::Portrait);

    QPrintPreviewDialog dialog(&printe,this);



    QPainter painter;
            painter.begin(&printe);
            double xscale = printe.pageRect().width()/double(ui->tableView->width());
            double yscale = printe.pageRect().height()/double(ui->tableView->height());
            double scale = qMin(xscale, yscale);
            painter.translate(printe.paperRect().x() + printe.pageRect().width()/2,
                               printe.paperRect().y() + printe.pageRect().height()/2);
            painter.scale(scale, scale);
            painter.translate(-width()/2, -height()/2);

            ui->tableView->render(&painter);


    connect(&dialog, SIGNAL(paintRequested(QPrinter *)),this,SLOT(print(QPrinter*)));
   dialog.showMaximized();
   dialog.exec();


   query.clear();
   db.close();
   */

}

void test::print(QPrinter * printer){
  //  text->print(printer);
   // doc->print(printer);
  // table->previousInFocusChain();


}


void test::on_donne_clicked()
{
    db.open();

    QSqlQuery recherche;
    QString recherche1;
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

    // ui->montant->setText(montant);
  //  ui->Date->setText(Date2);
     QSqlQueryModel * modal =new QSqlQueryModel();

     modal->setQuery(query);

     ui->tableView->setModel(modal);

     int Int0=0;
     QString Int2=QString::number(Int0);
    Delete.exec("UPDATE vente set cle='"+Int2+"' where cle='"+Int1+"'");
    query.clear();


   // layout1->addWidget(ui->tableView);
   // layout1->addWidget(Text);
    //layout1->addWidget(choix);
   // layout1->addWidget(button);
  //  setLayout(layout1);


   // QObject::connect(button, SIGNAL(clicked()), this , SLOT(writefile()));


    db.close();

}

void test::writefile1()
{

}


void test::on_save_clicked()
{
    db.open();
    QString fname="C:\\Users\\HP\\Desktop\\QT\\out5.txt";
    QFile file(fname);
    if(file.open(QIODevice::WriteOnly  | QIODevice::Text)){
       QTextStream stream(&file);
      // QString textfromspin=QString::number(box->value());
       //QString textfrombox=Text->toPlainText();
      // QString textfromcombo=choix->currentText();
       QSqlQuery query;

       query.exec("SELECT nom,prix_2,quantite,total from vente");

       QString recherche1;

       while(query.next()){
           recherche1 += "Nom : " + query.value(0).toString() +" ; " + "\t";
           recherche1 += "Prix : " + query.value(1).toString() + " ; "+ "\t";
           recherche1 += "QT : " + query.value(2).toString() + " ;" + "\t\t";
           recherche1 += "Totale : " + query.value(3).toString()+ "\t\n";
          // recherche1 += query.value(4).toString()+ "\n";
           //recherche1 += query.value(5).toString()+ "\n";
          // recherche1 += query.value(6).toString()+ "\n";
       }
       QSqlQueryModel * modal =new QSqlQueryModel();

       modal->setQuery(query);
      // QVector<QObject> texte=ui->tableView->setModel(modal);
       stream << " \t \t \t Liste des produits vendues \n" ;
     //  stream << " Nom \t\t Prix \t\t Quantite \t Total  \n";

       stream << recherche1 << endl;



    }

    file.close();
}

