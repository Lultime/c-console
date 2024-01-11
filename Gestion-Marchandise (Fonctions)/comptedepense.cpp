#include "comptedepense.h"
#include "ui_comptedepense.h"
#include "QMessageBox"
#include"QSqlQuery"
#include"modifierachat.h"
#include"QSqlQueryModel"

comptedepense::comptedepense(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comptedepense)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");
    db.open();

    QSqlQuery query;


   QString montant="";
    query.exec("SELECT SUM(quantite) FROM depense");
    while(query.next()){
    montant += query.value(0).toString() + "  Gourdes";
    }

 ui->montant->setText(montant);





}

comptedepense::~comptedepense()
{
    delete ui;
}
