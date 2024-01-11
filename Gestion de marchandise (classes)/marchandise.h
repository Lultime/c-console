#ifndef MARCHANDISE_H
#define MARCHANDISE_H

#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class marchandise;
}

class marchandise : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit marchandise(QWidget *parent = nullptr);
    ~marchandise();

private slots:
    void on_soumettre_clicked();

    void on_pushButton_clicked();

private:
    Ui::marchandise *ui;
};

#endif // MARCHANDISE_H
