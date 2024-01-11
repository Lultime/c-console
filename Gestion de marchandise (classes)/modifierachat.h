#ifndef MODIFIERACHAT_H
#define MODIFIERACHAT_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"

#include <QDialog>

namespace Ui {
class modifierachat;
}

class modifierachat : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
  QString Idachat;
    explicit modifierachat(QWidget *parent = nullptr);
    ~modifierachat();

private slots:
    void on_modifier_clicked();

    void on_annuler_clicked();

private:
    Ui::modifierachat *ui;
};

#endif // MODIFIERACHAT_H
