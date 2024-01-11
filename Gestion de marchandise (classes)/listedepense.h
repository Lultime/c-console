#ifndef LISTEDEPENSE_H
#define LISTEDEPENSE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>
#include"QPrinter"
#include"QPrintPreviewDialog"
#include"QTextEdit"
namespace Ui {
class listedepense;
}

class listedepense : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db;
    explicit listedepense(QWidget *parent = nullptr);
    ~listedepense();

private slots:
    void on_pushButton_clicked();


    void on_supprimer_clicked();

    void on_listerdepense_clicked();

    void on_mois_2_clicked();

    void on_jour_2_clicked();

    void on_anne_2_clicked();

    void on_tout_clicked();

    void on_enregistrer_clicked();

private:
    Ui::listedepense *ui;
    QTextEdit * text;

};

#endif // LISTEDEPENSE_H
