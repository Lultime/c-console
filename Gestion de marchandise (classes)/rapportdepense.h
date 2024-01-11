#ifndef RAPPORTDEPENSE_H
#define RAPPORTDEPENSE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>
#include"QPrinter"
#include"QPrintPreviewDialog"
#include"QTextEdit"

namespace Ui {
class rapportdepense;
}

class rapportdepense : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit rapportdepense(QWidget *parent = nullptr);
    ~rapportdepense();

private slots:
    void on_save_clicked();


    void on_print_clicked();

private:
    Ui::rapportdepense *ui;
    QTextEdit * text;

};

#endif // RAPPORTDEPENSE_H
