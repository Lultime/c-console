#ifndef MODIFIERVENTE_H
#define MODIFIERVENTE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include"QComboBox"
namespace Ui {
class modifiervente;
}

class modifiervente : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db;
     QString Nomproduit;
    explicit modifiervente(QWidget *parent = nullptr);
    ~modifiervente();

private slots:
    void on_modifier_clicked();

    void on_annuler_clicked();

    void on_id_clicked();

private:
    Ui::modifiervente *ui;
    QComboBox * combo=new QComboBox(this);
      QComboBox * combo2=new QComboBox(this);
};

#endif // MODIFIERVENTE_H
