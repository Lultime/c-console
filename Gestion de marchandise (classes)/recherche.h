#ifndef RECHERCHE_H
#define RECHERCHE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"

namespace Ui {
class recherche;
}

class recherche : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit recherche(QWidget *parent = nullptr);
    ~recherche();

private:
    Ui::recherche *ui;
};

#endif // RECHERCHE_H
