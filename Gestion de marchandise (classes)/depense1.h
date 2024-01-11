#ifndef DEPENSE1_H
#define DEPENSE1_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"

#include <QDialog>

namespace Ui {
class depense1;
}

class depense1 : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit depense1(QWidget *parent = nullptr);
    ~depense1();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::depense1 *ui;
};

#endif // DEPENSE1_H
