#ifndef MODIFIERMARCHANDISE_H
#define MODIFIERMARCHANDISE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class modifiermarchandise;
}

class modifiermarchandise : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit modifiermarchandise(QWidget *parent = nullptr);
    ~modifiermarchandise();

private slots:
    void on_modifier_clicked();

    void on_annuler_clicked();

    void on_acheter_clicked();

    void on_pushButton_clicked();

private:
    Ui::modifiermarchandise *ui;
};

#endif // MODIFIERMARCHANDISE_H
