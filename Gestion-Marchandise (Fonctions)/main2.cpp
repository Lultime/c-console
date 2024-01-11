#include "main2.h"
#include "ui_main2.h"
#include "QFrame"
#include"QFileDialog"
Main2::Main2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Main2)
{
    ui->setupUi(this);
    tabwidgete->setGeometry(0,20,700,300);

      tabwidgete->addTab(new QWidget , "tab1");
       tabwidgete->addTab(new QWidget , "tab2");
      tabwidgete->addTab(new QWidget , "tab3");
       tabwidgete->setMovable(true);
       tabwidgete->setTabsClosable(true);
}

Main2::~Main2()
{
    delete ui;
}

void Main2::on_actionNew_file_triggered()
{
    QFrame * tabframe=new QFrame(this);
    tabwidgete->addTab(tabframe , "untiled" );

}



void Main2::on_tabWidget_tabCloseRequested(int index)
{

}
/*
void Main2::on_actionopen_file_triggered()
{
    //QString Filepath=
}

*/
