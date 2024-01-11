#ifndef RAPPORTDACHAT_H
#define RAPPORTDACHAT_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>
#include"QPrinter"
#include"QPrintPreviewDialog"
#include"QTextEdit"


namespace Ui {
class rapportdachat;
}

class rapportdachat : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit rapportdachat(QWidget *parent = nullptr);
    ~rapportdachat();

private slots:
    void on_save_clicked();


    void on_print_clicked();

private:
    Ui::rapportdachat *ui;
    QTextEdit * text;

};

#endif // RAPPORTDACHAT_H
