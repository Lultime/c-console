#include "achatlistes.h"
#include "ui_achatlistes.h"

achatlistes::achatlistes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::achatlistes)
{
    ui->setupUi(this);

}

achatlistes::~achatlistes()
{
    delete ui;
}

void achatlistes::on_nextpage_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}


void achatlistes::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);

}

