#ifndef TEST2_H
#define TEST2_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include"QPrinter"
#include"QPrintPreviewDialog"
#include"QTextEdit"
#include"QTableView"
#include"QTextDocument"
#include"QFile"
#include"QTextEdit"
#include"QPushButton"
#include"QTextStream"
#include"QSpinBox"
#include"QHBoxLayout"
#include"QVBoxLayout"
#include"QIODevice"
#include"QComboBox"
#include <QDialog>
#include"QMenuBar"
namespace Ui {
class test2;
}

class test2 : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db;
    explicit test2(QWidget *parent = nullptr);
    ~test2();

private slots:
    void on_parcourir_clicked();
    void textEditChanged();

private:
    Ui::test2 *ui;
     QList<QSqlQuery> produit;
     QMenuBar *menu=new QMenuBar(this);
};

#endif // TEST2_H
