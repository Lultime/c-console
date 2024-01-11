#ifndef DEPENSE_H
#define DEPENSE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"

namespace Ui {
class depense;
}

class depense : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit depense(QWidget *parent = nullptr);
    ~depense();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::depense *ui;
};

#endif // DEPENSE_H
