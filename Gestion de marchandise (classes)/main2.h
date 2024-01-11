#ifndef MAIN2_H
#define MAIN2_H
#include"QWidget"
#include <QMainWindow>

namespace Ui {
class Main2;
}

class Main2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main2(QWidget *parent = nullptr);
    ~Main2();

private slots:
    void on_actionNew_file_triggered();

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::Main2 *ui;
    QTabWidget * tabwidgete=new QTabWidget(this);

};

#endif // MAIN2_H
