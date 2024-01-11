#ifndef TABWIDGET_H
#define TABWIDGET_H
#include"QTabWidget"
#include <QDialog>

namespace Ui {
class tabwidget;
}

class tabwidget : public QDialog
{
    Q_OBJECT

public:
    explicit tabwidget(QWidget *parent = nullptr);
    ~tabwidget();

private:
    Ui::tabwidget *ui;
    QTabWidget * tabwidgete=new QTabWidget(this);
};

#endif // TABWIDGET_H
