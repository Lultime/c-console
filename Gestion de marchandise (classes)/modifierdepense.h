#ifndef MODIFIERDEPENSE_H
#define MODIFIERDEPENSE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"


namespace Ui {
class modifierdepense;
}

class modifierdepense : public QDialog
{
    Q_OBJECT

public:
     QSqlDatabase db;
    explicit modifierdepense(QWidget *parent = nullptr);
    ~modifierdepense();

private slots:
    void on_modifier_clicked();

    void on_annuler_clicked();

private:
    Ui::modifierdepense *ui;
};

#endif // MODIFIERDEPENSE_H
