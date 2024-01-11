#include "server.h"
#include "ui_server.h"
#include"QMessageBox"
server::server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::server)
{
    ui->setupUi(this);
    Tcpserver = new QTcpServer();
    if(Tcpserver->listen(QHostAddress::Any,8080)){
        connect(Tcpserver, SIGNAL(newConnection()), this , SLOT(newConnection()));

        QMessageBox::information(this, "message", "server start correctly");

    }else{
        QMessageBox::critical(this, "message", "server start fail");
    }
}

server::~server()
{
    delete ui;
}

void server::newConnection()
{
    while(Tcpserver->hasPendingConnections()){
        add_new_connection(Tcpserver->nextPendingConnection());
    }
}

void server::Read_Data_From_Server()
{

}

void server::add_new_connection(QTcpSocket * socket)
{
    client_connexion_list.append(socket);
    connect(socket, SIGNAL(readyRead()), this , SLOT(Read_Data_From_Server));
    ui->combo_client_list->addItem(QString::number(socket->socketDescriptor()));
    QString client= " client : " + QString::number(socket->socketDescriptor()) + " connected with the server";
    ui->textmessage->append(client);
}

void server::on_sendmessage_clicked()
{
    QString Message_for_client=ui->linemessage->text();
    QString receiver=ui->combo_client_list->currentText();
    if(ui->combo_send_message_type->currentText() == "All"){// send message for all connected client
        foreach(QTcpSocket * socket,client_connexion_list){
            socket->write(Message_for_client.toStdString().c_str());

}
    }
    else{// send message to only selected connected client
        foreach(QTcpSocket * socket,client_connexion_list){
            if(socket->socketDescriptor() == receiver.toLongLong()){
                socket->write(Message_for_client.toStdString().c_str());
            }
        }
    }
}

