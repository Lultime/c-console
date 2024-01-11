#ifndef LISTEACHAT_H
#define LISTEACHAT_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>
#include"QPrinter"
#include"QPrintPreviewDialog"
#include"QTextEdit"

namespace Ui {
class listeachat;
}

class listeachat : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit listeachat(QWidget *parent = nullptr);
    ~listeachat();

private slots:
    void on_pushButton_2_clicked();




    void on_listeractivite_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_anne_2_clicked();

    void on_jour_2_clicked();

    void on_mois_2_clicked();

    void on_tout_clicked();

    void on_commandLinkButton_clicked();

    void on_enregistrer_clicked();

private:
    Ui::listeachat *ui;
    QTextEdit * text;

};

#endif // LISTEACHAT_H
