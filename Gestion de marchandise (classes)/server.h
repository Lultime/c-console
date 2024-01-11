#ifndef SERVER_H
#define SERVER_H
#include"QtNetwork/QTcpServer"
#include"QtNetwork/QTcpSocket"
#include"QList"
#include"QtDebug"
#include"QByteArray"
#include"QString"

#include <QDialog>

namespace Ui {
class server;
}

class server : public QDialog
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();
private slots:
  void  newConnection();
  void Read_Data_From_Server();
  void on_sendmessage_clicked();

private:
  void add_new_connection(QTcpSocket * socket);
private:
    Ui::server *ui;
    QTcpServer * Tcpserver;
    QList<QTcpSocket *> client_connexion_list;
};

#endif // SERVER_H
