#ifndef REDIGERRAPPORTDEPENSE_H
#define REDIGERRAPPORTDEPENSE_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class redigerrapportdepense;
}

class redigerrapportdepense : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit redigerrapportdepense(QWidget *parent = nullptr);
    ~redigerrapportdepense();

private slots:
    void on_autredepense_clicked();

    void on_annuler_clicked();

    void on_termine_clicked();

private:
    Ui::redigerrapportdepense *ui;
};

#endif // REDIGERRAPPORTDEPENSE_H
