#ifndef LISTEMARCHANDISE_H
#define LISTEMARCHANDISE_H

#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>
#include"QPrinter"
#include"QPrintPreviewDialog"
#include"QTextEdit"
#include"marchandise.h"

namespace Ui {
class listemarchandise;
}

class listemarchandise : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    marchandise * Marchandise;
    explicit listemarchandise(QWidget *parent = nullptr);
    ~listemarchandise();

private slots:
    void on_pushButton_2_clicked();


    void on_listerproduit_clicked();

    void on_mois_2_clicked();

    void on_jour_2_clicked();

    void on_anne_2_clicked();

    void on_tout_clicked();

    void on_pushButton_clicked();

    void on_enregistrer_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::listemarchandise *ui;
    QTextEdit * text;

};

#endif // LISTEMARCHANDISE_H
