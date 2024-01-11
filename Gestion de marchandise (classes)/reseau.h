#ifndef RESEAU_H
#define RESEAU_H
#include"QtNetwork/QTcpSocket"
#include"QtNetwork/QHostAddress"
#include"QtDebug"
#include"QByteArray"
#include"QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include <QDialog>
#include"QSqlQuery"
#include"QPrinter"
#include"QPrintPreviewDialog"
#include"QTextEdit"
#include"QTableView"
#include"QTextDocument"
#include"QDataStream"
#include <QDialog>

namespace Ui {
class reseau;
}

class reseau : public QDialog
{
    Q_OBJECT

public:
    explicit reseau(QWidget *parent = nullptr);
    ~reseau();

private slots:
    void on_senddata_clicked();
    void read_data();

private:
    Ui::reseau *ui;
    QTcpSocket * Tcpsocket;

};

#endif // RESEAU_H
