#include "recherche.h"
#include "ui_recherche.h"
#include"QSqlQuery"
#include"QMessageBox"

recherche::recherche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recherche)
{
    ui->setupUi(this);
    db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/marchandise/marchandise.sqlite");

    db.open();

}

recherche::~recherche()
{
    delete ui;
}
