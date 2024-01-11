#ifndef BENEFICE_H
#define BENEFICE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>

namespace Ui {
class benefice;
}

class benefice : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit benefice(QWidget *parent = nullptr);
    ~benefice();

private slots:
    void on_mois_2_clicked();

    void on_jour_2_clicked();

    void on_anne_2_clicked();

    void on_tout_2_clicked();

private:
    Ui::benefice *ui;
};

#endif // BENEFICE_H
