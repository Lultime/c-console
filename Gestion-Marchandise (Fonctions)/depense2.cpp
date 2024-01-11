#include "depense2.h"
#include "ui_lister.h"

depense2::depense2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::depense2)
{
    ui->setupUi(this);
}

lister::~lister()
{
    delete ui;
}
