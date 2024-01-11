#include "connexion.h"
#include "accueil.h"
#include"main2.h"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include"QSqlQuery"
#include "utilisateur.h"
#include <QApplication>
#include"QMessageBox"
#include"start.h"
#include"test2.h"
#include"same.h"
#include"fichevente.h"
#include"reseau.h"
#include"server.h"
#include"tabwidget.h"
#include"achatlistes.h"
#include"test.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

start w;
  w.show();

 return a.exec();
}
