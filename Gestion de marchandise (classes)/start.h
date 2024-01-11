#ifndef START_H
#define START_H
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"

namespace Ui {
class start;
}

class start : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit start(QWidget *parent = nullptr);
    ~start();

private:
    Ui::start *ui;
};

#endif // START_H
