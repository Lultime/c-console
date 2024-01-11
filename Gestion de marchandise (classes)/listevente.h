#ifndef LISTEVENTE_H
#define LISTEVENTE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>
#include"QPrinter"
#include"QPrintPreviewDialog"
#include"QTextEdit"

namespace Ui {
class listevente;
}

class listevente : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit listevente(QWidget *parent = nullptr);
    ~listevente();

private slots:
    void on_supprimer_clicked();


    void on_listerfond_clicked();

    void on_mois_2_clicked();

    void on_jour_2_clicked();

    void on_anne_2_clicked();

    void on_tout_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
     void opentabfile(QString filepatch);
     void currenttextedit();
private:
    Ui::listevente *ui;
    QTextEdit * text;

};

#endif // LISTEVENTE_H
