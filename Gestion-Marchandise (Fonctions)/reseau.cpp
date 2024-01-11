#include "reseau.h"
#include "ui_reseau.h"
#include"QMessageBox"
reseau::reseau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reseau)
{
    ui->setupUi(this);
    Tcpsocket =new QTcpSocket();
    connect(Tcpsocket, SIGNAL(readyRead()), this, SLOT(read_data()));
    Tcpsocket->connectToHost(QHostAddress::LocalHost,8080);
    Tcpsocket->open(QIODevice::ReadWrite);
    if(Tcpsocket->isOpen()){
        QMessageBox::information(this, "message", "connected to the server");

    }else{
        QMessageBox::critical(this, "message", "not connected to the server");
    }
}

reseau::~reseau()
{
    delete ui;
}

void reseau::on_senddata_clicked()
{
    if( Tcpsocket){
        if( Tcpsocket->isOpen()){
            QString write=ui->data->text();

             Tcpsocket->write(write.toStdString().c_str());
        }else{
            QMessageBox::critical(this,"message","error : "+ Tcpsocket->errorString());
        }
    }else{
        QMessageBox::critical(this,"message","error : "+ Tcpsocket->errorString());
    }
}

void reseau::read_data()
{
    if( Tcpsocket){
        if( Tcpsocket->isOpen()){
            QByteArray read_data_rom_server= Tcpsocket->readAll();
          //  QDataStream DataIN(&read_data_rom_server,QIODevice::ReadOnly);
         //   DataIN.setVersion(QDataStream::Version::Qt_5_12);

            QString messagestring = QString::fromStdString(read_data_rom_server.toStdString());
        //    while (DataIN.atEnd() == false) {
         //       DataIN >>  messagestring;
          //  }
          ui->textdata->append(messagestring);
        }
    }
}

