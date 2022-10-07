#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    float Med_devisa(int f,float z, float N[2]);
    float Med_febonachi(int f,float N[2],float res);
    float Med_payala(int f,float N[2],float res);

    void calculateBtn();

};
#endif // MAINWINDOW_H
