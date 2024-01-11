#ifndef SAME_H
#define SAME_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"

namespace Ui {
class same;
}

class same : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;

    explicit same(QWidget *parent = nullptr);
    ~same();

private slots:
    void on_pushButton_clicked();

    void on_termine_clicked();

    void on_autreproduit_clicked();

    void on_annuler_clicked();

private:
    Ui::same *ui;
};

#endif // SAME_H
