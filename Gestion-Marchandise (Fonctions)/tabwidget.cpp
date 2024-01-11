#include "tabwidget.h"
#include "ui_tabwidget.h"
#include "QFrame"
#include "QTabWidget"
tabwidget::tabwidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tabwidget)
{
    ui->setupUi(this);



  //  tabwidgete->addTab(new QWidget , "tab1");
  //  tabwidgete->addTab(new QWidget , "tab2");
  //  tabwidgete->addTab(new QWidget , "tab3");
  //  tabwidgete->setMovable(true);
   // tabwidgete->setTabsClosable(true);


}

tabwidget::~tabwidget()
{
    delete ui;
}
