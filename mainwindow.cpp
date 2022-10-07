#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cmath>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->calculateBtn,SIGNAL(clicked()),this,SLOT(calculateBtn()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateBtn(){

    float Predel[2];
    float zero = ui->zero->value();
    float res = 0;

    if(ui->function1->isChecked()){
        qDebug()<<"1 функция";
        Med_devisa(1,zero,Predel);

        if(ui->method1->isChecked()){
           qDebug()<<"1 метод";
           res = Med_febonachi(1,Predel,res);
        }
        else if(ui->method2->isChecked()){
           qDebug()<<"2 метод";
           res = Med_payala(1,Predel,res);
        }
        else {
            qDebug()<<"метод не выбран";
        }
    }
    if(ui->function2->isChecked()){
        qDebug()<<"2 функция";
        Med_devisa(2,zero,Predel);

        if(ui->method1->isChecked()){
           qDebug()<<"1 метод";
           res = Med_febonachi(2,Predel,res);
        }
        else if(ui->method2->isChecked()){
           qDebug()<<"2 метод";
           res = Med_payala(2,Predel,res);
        }
        else {
            qDebug()<<"метод не выбран";
        }
    }
    if(ui->function3->isChecked()){
        qDebug()<<"3 функция";
        Med_devisa(3,zero,Predel);

        if(ui->method1->isChecked()){
           qDebug()<<"1 метод";
           res = Med_febonachi(3,Predel,res);
        }
        else if(ui->method2->isChecked()){
           qDebug()<<"2 метод";
           res = Med_payala(3,Predel,res);
        }
        else {
            qDebug()<<"метод не выбран";
        }
    }
    if(ui->function4->isChecked()){
        qDebug()<<"4 функция";
        Med_devisa(4,zero,Predel);

        if(ui->method1->isChecked()){
           qDebug()<<"1 метод";
           res = Med_febonachi(4,Predel,res);
        }
        else if(ui->method2->isChecked()){
           qDebug()<<"2 метод";
           res = Med_febonachi(4,Predel,res);
           //res = Med_payala(4,Predel,res);
        }
        else {
            qDebug()<<"метод не выбран";
        }
    }
    if(ui->function5->isChecked()){
        qDebug()<<"5 функция";
        Med_devisa(5,zero,Predel);

        if(ui->method1->isChecked()){
           qDebug()<<"1 метод";
           res = Med_febonachi(5,Predel,res);
        }
        else if(ui->method2->isChecked()){
           qDebug()<<"2 метод";
           res = Med_payala(5,Predel,res);
        }
        else {
            qDebug()<<"метод не выбран";
        }
    }
    if(ui->function6->isChecked()){
        qDebug()<<"6 функция";
        Med_devisa(6,zero,Predel);

        if(ui->method1->isChecked()){
           qDebug()<<"1 метод";
           res = Med_febonachi(6,Predel,res);
        }
        else if(ui->method2->isChecked()){
           qDebug()<<"2 метод";
           res = Med_payala(6,Predel,res);
        }
        else {
            qDebug()<<"метод не выбран";
        }
    }

    ui->interval->setText("["+QString::number(Predel[0])+":"+QString::number(Predel[1])+"]");
    ui->xmin->setText(QString::number(res));
}

float MainWindow::Med_devisa(int f,float z,float N[2]){

    int step = 1;
    float fx0=0;    //у при начальной точке
    float fx1=0;    //у при точке + 1 шаг
    float fx_1=0;   //у при точке - 1 шаг
    float x1=0;     //z + шаг
    float xk=0;     //z + 2 * шаг
    float h=1;      //шаг
    float fxk=0;    //у при хк
    float xk_1=0;   //хк - 1
    float xk_2=0;   //xk - 2
    float fxk_1=0;  //у при хл_1
    float a=0;
    float b = 0;
    float k = 0;

    for (int i=0;i<1;i++) {
        if(step == 1){                          //Шаг 1
            if(f==1){                   //Выбор нужной функции
                fx0 = (z-1)*(z-1);
                z+=h;
                fx1 = (z-1)*(z-1);
                z-=h;
            }
            else if(f==2){
                fx0 = (z*z*z*4)-(z*z*8)-(z*11)+5;
                z+=h;
                fx1 = (z*z*z*4)-(z*z*8)-(z*11)+5;
                z-=h;
            }
            else if(f==3){
                fx0 = z+((3)/(z*z));
                z+=h;
                fx1 = z+((3)/(z*z));
                z-=h;
            }
            else if(f==4){
                fx0 = (z+2.5)/(4-(z*z));
                z+=h;
                fx1 = (z+2.5)/(4-(z*z));
                z-=h;
            }
            else if(f==5){
                fx0 = -sin(z)-(sin(3*z))/(3);
                z+=h;
                fx1 = -sin(z)-(sin(3*z))/(3);
                z-=h;
            }
            else if(f==6){
                fx0 = -2*sin(z)-sin(2*z)-(sin(3*z))/(3);
                z+=h;
                fx1 = -2*sin(z)-sin(2*z)-(sin(3*z))/(3);
                z-=h;
            }
            step++;
        }
        else if(step==2){                       //Шаг 2

            if (fx0 > fx1){
                a = z;
                x1 = z + h;
                k = 2;
                step=4;
            }
            else {
                if(f==1){                   //Выбор нужной функции
                    z-=h;
                    fx_1 = (z-1)*(z-1);
                    z+=h;
                }
                else if(f==2){
                    z-=h;
                    fx_1 = (z*z*z*4)-(z*z*8)-(z*11)+5;
                    z+=h;
                }
                else if(f==3){
                    z-=h;
                    fx_1 = z+((3)/(z*z));
                    z+=h;
                }
                else if(f==4){
                    z-=h;
                    fx_1 = (z+2.5)/(4-(z*z));
                    z+=h;
                }
                else if(f==5){
                    z-=h;
                    fx_1 = -sin(z)-(sin(3*z))/(3);
                    z+=h;
                }
                else if(f==6){
                    z-=h;
                    fx_1 = -2*sin(z)-sin(2*z)-(sin(3*z))/(3);
                    z+=h;
                }
                step=3;
            }
        }
        else if(step==3){                       //Шаг 3

            if (fx_1 >= fx0){
                a = z - h;
                b = z + h;
                step=6;
            }
            else {
                b = z;
                x1 = z - h;
                k = 2;
                step=4;
            }
        }
        else if(step==4){                       //Шаг 4
            int k2 = 1;
            for (int j=0;j<k-1;j++) {
                k2 = k2 * 2;
            }
            xk=z+k2*h;

            //--------------------

            if(f==1){                   //Выбор нужной функции
                fxk = (xk-1)*(xk-1);
            }
            else if(f==2){
                fxk = (xk*xk*xk*4)-(xk*xk*8)-(xk*11)+5;
            }
            else if(f==3){
                fxk = xk+((3)/(xk*xk));
            }
            else if(f==4){
                fxk = (xk+2.5)/(4-(xk*xk));
            }
            else if(f==5){
                fxk = -sin(xk)-(sin(3*xk))/(3);
            }
            else if(f==6){
                fxk = -2*sin(xk)-sin(2*xk)-(sin(3*xk))/(3);
            }
            step=5;
        }
        else if(step==5){                       //Шаг 5
            xk_1 = xk - 1;

            //-------------------

            if(f==1){                   //Выбор нужной функции
                fxk_1 = (xk_1-1)*(xk_1-1);
            }
            else if(f==2){
                fxk_1 = (xk_1*xk_1*xk_1*4)-(xk_1*xk_1*8)-(xk_1*11)+5;
            }
            else if(f==3){
                fxk_1 = xk_1+((3)/(xk_1*xk_1));
            }
            else if(f==4){
                fxk_1 = (xk_1+2.5)/(4-(xk_1*xk_1));
            }
            else if(f==5){
                fxk_1 = -sin(xk_1)-(sin(3*xk_1))/(3);
            }
            else if(f==6){
                fxk_1 = -2*sin(xk_1)-sin(2*xk_1)-(sin(3*xk_1))/(3);
            }

            //-------------------

            if(fxk_1<=fxk){
                if(h>0){
                    b=xk;
                    step=6;
                }
                else {
                    a=xk;
                    step=6;
                }
            }
            else {
                if(h>0){
                    xk_2 = xk - 2;
                    a=xk_2;
                }
                else {
                    b=xk;
                }
                k = k + 1;
                step=4;
            }
        }
        else if(step==6){                       //Шаг 6
            i++;
        }

        i--;
    }
    N[0]= a;
    N[1]= b;


    return *N;
}
float MainWindow::Med_febonachi(int f,float N[2],float res){

    int step = 1;
    QList <float> febon;      //лист чисел фебоначи
    febon << 1.0 << 1.0;
    int chet;               //число фебоначи
    int k=0;
    float x1=0;
    float x2=0;
    float fx1=0;
    float fx2=0;
    float a = (float)N[0];
    float b = (float)N[1];

    for (int i=0;i<1;i++) {
        if(step == 1){
            float chislo = 0;             //новое число фебоначи
            float Fn = ((b-a)/(2 * 0.001)) ;
            for (chet=2;chislo < Fn ;chet++) {
                 chislo = febon[chet - 1] + febon[chet - 2];
                 febon << chislo;
            }
            chet--;
            step++;
        }
        else if (step == 2) {
            k=0;
            step++;
        }
        else if (step == 3) {
            x1=a+(febon[chet-2])*(b-a)/(febon[chet]);
            x2=a+(febon[chet-1])*(b-a)/(febon[chet]);
            step++;
        }
        else if (step == 4) {
            if(f==1){               //Выбор нужной функции
                fx1=(x1-1)*(x1-1);
                fx2=(x2-1)*(x2-1);
            }
            else if (f==2){
                fx1=(x1*x1*x1*4)-(x1*x1*8)-(x1*11)+5;
                fx2=(x2*x2*x2*4)-(x2*x2*8)-(x2*11)+5;
            }
            else if (f==3){
                fx1=x1+((3)/(x1*x1));
                fx2=x2+((3)/(x2*x2));
            }
            else if (f==4){
                fx1=(x1+2.5)/(4-(x1*x1));
                fx2=(x2+2.5)/(4-(x2*x2));
            }
            else if (f==5){
                fx1=-sin(x1)-(sin(3*x1))/(3);
                fx2=-sin(x2)-(sin(3*x2))/(3);
            }
            else if (f==6){
                fx1=-2*sin(x1)-sin(2*x1)-(sin(3*x1))/(3);
                fx2=-2*sin(x2)-sin(2*x2)-(sin(3*x2))/(3);
            }
            step++;
        }
        else if (step == 5) {
            if(fx1<=fx2){
                b=x2;
                x2=x1;
                x1=a+(febon[chet-k-3])*(b-a)/(febon[chet-k-1]);
            }
            else {
                a=x1;
                x1=x2;
                x2=a+(febon[chet-k-2])*(b-a)/(febon[chet-k-1]);
               }
            step++;
        }
        else if (step == 6) {
            if(k == chet - 3){
                x2=x1+0.0001;

                if(f==1){               //Выбор нужной функции
                    fx1=(x1-1)*(x1-1);
                    fx2=(x2-1)*(x2-1);
                }
                else if (f==2){
                    fx1=(x1*x1*x1*4)-(x1*x1*8)-(x1*11)+5;
                    fx2=(x2*x2*x2*4)-(x2*x2*8)-(x2*11)+5;
                }
                else if (f==3){
                    fx1=x1+((3)/(x1*x1));
                    fx2=x2+((3)/(x2*x2));
                }
                else if (f==4){
                    fx1=(x1+2.5)/(4-(x1*x1));
                    fx2=(x2+2.5)/(4-(x2*x2));
                }
                else if (f==5){
                    fx1=-sin(x1)-(sin(3*x1))/(3);
                    fx2=-sin(x2)-(sin(3*x2))/(3);
                }
                else if (f==6){
                    fx1=-2*sin(x1)-sin(2*x1)-(sin(3*x1))/(3);
                    fx2=-2*sin(x2)-sin(2*x2)-(sin(3*x2))/(3);
                }

                //------------------------

                if(fx1 <= fx2){
                    b=x2;
                }
                else{
                    a=x1;
                }
                step = 7;
            }
            else{
                k=k+1;
                step = 4;
            }

        }
        else if (step == 7) {
            res = (a+b)/(2);
            i++;
        }

        i--;
    }

    return res;
}
float MainWindow::Med_payala(int f,float N[2],float res){

    int step = 1;
    float a = (float)N[0];
    float b = (float)N[1];
    float x1=0;
    float x2=0;
    float x3=0;
    float x4=0;
    float xmin=0;
    float fx1=0;
    float fx2=0;
    float fx3=0;
    float fx4=0;
    float Xposled[4];
    float Fposled[4];
    float temp_x;         // временная переменная для обмена элементов местами
    float temp_f;

    for (int i=0;i<1;i++){
        if(step == 1){
            x1=a;
            x2=(a+b)/2;
            x3=b;
            Xposled[0]=x1;
            Xposled[1]=x2;
            Xposled[2]=x3;
            step++;
        }
        else if (step == 2){        //Выбор нужной функции
            if(f==1){
                fx1=(x1-1)*(x1-1);
                fx2=(x2-1)*(x2-1);
                fx3=(x3-1)*(x3-1);
            }
            else if (f==2){
                fx1=(x1*x1*x1*4)-(x1*x1*8)-(x1*11)+5;
                fx2=(x2*x2*x2*4)-(x2*x2*8)-(x2*11)+5;
                fx3=(x3*x3*x3*4)-(x3*x3*8)-(x3*11)+5;
            }
            else if (f==3){
                fx1=x1+((3)/(x1*x1));
                fx2=x2+((3)/(x2*x2));
                fx3=x3+((3)/(x3*x3));
            }
            else if (f==4){
                fx1=(x1+2.5)/(4-(x1*x1));
                fx2=(x2+2.5)/(4-(x2*x2));
                fx3=(x3+2.5)/(4-(x3*x3));
            }
            else if (f==5){
                fx1=-sin(x1)-(sin(3*x1))/(3);
                fx2=-sin(x2)-(sin(3*x2))/(3);
                fx3=-sin(x3)-(sin(3*x3))/(3);
            }
            else if (f==6){
                fx1=-2*sin(x1)-sin(2*x1)-(sin(3*x1))/(3);
                fx2=-2*sin(x2)-sin(2*x2)-(sin(3*x2))/(3);
                fx3=-2*sin(x3)-sin(2*x3)-(sin(3*x3))/(3);
            }

            if(fx1<fx2 && fx1<fx3){
                xmin = x1;
            }
            else if(fx2<fx1 && fx2<fx3){
                xmin = x2;
            }
            else if(fx3<fx1 && fx3<fx2){
                xmin = x3;
            }

            step++;
        }
        else if (step == 3){
            x4=((x2*x2-x3*x3)*fx1+(x3*x3-x1*x1)*fx2+(x1*x1-x2*x2)*fx3)/(2*((x2-x3)*fx1+(x3-x1)*fx2+(x1-x2)*fx3));
            Xposled[3]=x4;
            step++;
        }
        else if (step == 4){
            if(abs(x4-xmin)<=0.01){
                step=7;
            }
            else {
                step=5;
            }
        }
        else if (step == 5){
            for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3 - i; j++) {
                        if (Xposled[j] > Xposled[j + 1]) {
                            temp_x = Xposled[j];
                            Xposled[j] = Xposled[j + 1];
                            Xposled[j + 1] = temp_x;
                        }
                    }
                }
            x1 = Xposled[0];
            x2 = Xposled[1];
            x3 = Xposled[2];
            x4 = Xposled[3];
            step=6;
        }
        else if (step == 6){
            if(f==1){
                fx1=(x1-1)*(x1-1);
                fx2=(x2-1)*(x2-1);
                fx3=(x3-1)*(x3-1);
                fx4=(x4-1)*(x4-1);
            }
            else if (f==2){
                fx1=(x1*x1*x1*4)-(x1*x1*8)-(x1*11)+5;
                fx2=(x2*x2*x2*4)-(x2*x2*8)-(x2*11)+5;
                fx3=(x3*x3*x3*4)-(x3*x3*8)-(x3*11)+5;
                fx4=(x4*x4*x4*4)-(x4*x4*8)-(x4*11)+5;
            }
            else if (f==3){
                fx1=x1+((3)/(x1*x1));
                fx2=x2+((3)/(x2*x2));
                fx3=x3+((3)/(x3*x3));
                fx4=x4+((3)/(x4*x4));
            }
            else if (f==4){
                fx1=(x1+2.5)/(4-(x1*x1));
                fx2=(x2+2.5)/(4-(x2*x2));
                fx3=(x3+2.5)/(4-(x3*x3));
                fx4=(x4+2.5)/(4-(x4*x3));
            }
            else if (f==5){
                fx1=-sin(x1)-(sin(3*x1))/(3);
                fx2=-sin(x2)-(sin(3*x2))/(3);
                fx3=-sin(x3)-(sin(3*x3))/(3);
                fx4=-sin(x4)-(sin(3*x4))/(3);
            }
            else if (f==6){
                fx1=-2*sin(x1)-sin(2*x1)-(sin(3*x1))/(3);
                fx2=-2*sin(x2)-sin(2*x2)-(sin(3*x2))/(3);
                fx3=-2*sin(x3)-sin(2*x3)-(sin(3*x3))/(3);
                fx4=-2*sin(x4)-sin(2*x4)-(sin(3*x4))/(3);
            }

            Fposled[0]=fx1;
            Fposled[1]=fx2;
            Fposled[2]=fx3;
            Fposled[3]=fx4;

            for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3 - i; j++) {
                        if (Fposled[j] > Fposled[j + 1]) {
                            temp_f = Fposled[j];
                            Fposled[j] = Fposled[j + 1];
                            Fposled[j + 1] = temp_f;

                            temp_x = Xposled[j];
                            Xposled[j] = Xposled[j + 1];
                            Xposled[j + 1] = temp_x;
                        }
                    }
                }

            // Костыль)
            if((Fposled[0] != Fposled[1]) && (Fposled[1] != Fposled[2])){
                x1 = Xposled[0];
                x2 = Xposled[1];
                x3 = Xposled[2];
            }
            else if(Fposled[0] == Fposled[1]){
                x1 = Xposled[1];
                x2 = Xposled[2];
                x3 = Xposled[3];
            }
            else if(Fposled[1] == Fposled[2]){
                x1 = Xposled[0];
                x2 = Xposled[1];
                x3 = Xposled[3];
            }

            /*
            x1 = Xposled[0];
            x2 = Xposled[1];
            x3 = Xposled[2];
            */

            step=2;
        }
        else if (step == 7){
            res = x4;
            i++;
        }

        i--;
    }

    return res;
}
