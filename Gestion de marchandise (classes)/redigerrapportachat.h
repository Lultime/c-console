#ifndef REDIGERRAPPORTACHAT_H
#define REDIGERRAPPORTACHAT_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include <QDialog>

namespace Ui {
class redigerrapportachat;
}

class redigerrapportachat : public QDialog
{
    Q_OBJECT

public:
  QSqlDatabase db;
    explicit redigerrapportachat(QWidget *parent = nullptr);
    ~redigerrapportachat();

private slots:
    void on_autreachat_clicked();

    void on_annuler_clicked();

    void on_termine_clicked();

private:
    Ui::redigerrapportachat *ui;
};

#endif // REDIGERRAPPORTACHAT_H
