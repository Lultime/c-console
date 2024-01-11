#ifndef TEST_H
#define TEST_H
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
#include"QLineEdit"
class Myclass:public QDialog{
    Q_OBJECT

public:
    QSqlDatabase db;
    QComboBox* choix;
    QPushButton * button;
    QSpinBox * box;
    QTextEdit * Text;
    QHBoxLayout * layout;
    QLineEdit * line;
    explicit Myclass(QWidget * parent=0);
private slots:
    void writefile();

};

namespace Ui {
class test;
}

class test : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db;
    explicit test(QWidget *parent = nullptr);
    ~test();

private slots:
     void on_pushButton_clicked();
     void writefile1();

     void on_pushButton_2_clicked();
     void print(QPrinter * printer);

     void on_lineEdit_textChanged(const QString &arg1);

     void on_print_clicked();

     void on_donne_clicked();

     void on_save_clicked();

private:
    Ui::test *ui;
    QTextEdit * text;
    QTextDocument * doc;
    QTableView * table;\
    QList<QSqlQuery> produit;
    QHBoxLayout * layout1;

};

#endif // TEST_H
