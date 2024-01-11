#ifndef VENTE_H
#define VENTE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include"QComboBox"

namespace Ui {
class vente;
}

class vente : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db;
     QString Nomproduit;
     QSqlQuery query,query2;


    explicit vente(QWidget *parent = nullptr);
    ~vente();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();



    void on_id_clicked();

private:
    Ui::vente *ui;
  QComboBox * combo=new QComboBox(this);
    QComboBox * combo2=new QComboBox(this);
};

#endif // VENTE_H
