#ifndef FICHEVENTE_H
#define FICHEVENTE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include"QPrinter"
#include"QPrintPreviewDialog"
#include"QTextEdit"
#include <QDialog>
#include"QTableView"
#include"QLineEdit"
#include"QSaveFile"

namespace Ui {
class fichevente;
}

class fichevente : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit fichevente(QWidget *parent = nullptr);
    ~fichevente();

private slots:
    void on_pushButton_clicked();
    void print(QPrinter * printer);
    void print2(QPrinter * print2);

    void on_print_clicked();

    void on_save_clicked();

private:
    Ui::fichevente *ui;
       QTextEdit * titree;
    QTextEdit * text;
     QTextEdit * titre;
     QTableView * table;
    QTextEdit * datee;
   QTextEdit * total;
   QLineEdit * line;
};

#endif // FICHEVENTE_H
