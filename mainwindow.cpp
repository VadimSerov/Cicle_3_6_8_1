#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    unsigned long long int p = ui->lineEdit->text().toULongLong();
    unsigned long long int i,j;
    unsigned long long int simple = p / 2;
    bool trap;

    for (i=p/2;i<=p;i++){
        trap = true;
        j=2;
        while(j*j<=p){
            if(i%j==0){
                trap = false;
            }
            j++;
        }
        if (trap){
            simple=i;
        }
    }
    ui->label_3->setText(QString::number(simple));
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    unsigned long long int p = ui->lineEdit->text().toULongLong();
    ui->label_4->setText("Предположительное количество секунд : "+QString::number(p/2*sqrt(p)/40000000));
}
