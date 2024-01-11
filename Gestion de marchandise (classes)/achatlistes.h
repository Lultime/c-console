#ifndef ACHATLISTES_H
#define ACHATLISTES_H

#include <QMainWindow>

namespace Ui {
class achatlistes;
}

class achatlistes : public QMainWindow
{
    Q_OBJECT

public:
    explicit achatlistes(QWidget *parent = nullptr);
    ~achatlistes();

private slots:
    void on_nextpage_clicked();

    void on_pushButton_clicked();

private:
    Ui::achatlistes *ui;
};

#endif // ACHATLISTES_H
