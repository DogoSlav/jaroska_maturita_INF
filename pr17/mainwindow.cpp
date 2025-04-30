#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_nuluj_out_clicked()
{
    ui->output->setText("0");
}


void MainWindow::on_nuluj_add_clicked()
{
    ui->pricist->setText("0");
}


void MainWindow::on_jedna_clicked()
{
    if (ui->pricist->text() == "0"){
        ui->pricist->setText("");
    }
    QString textik = ui->pricist->text();
    ui->pricist->setText(textik + "1");
}


void MainWindow::on_jedna_2_clicked()
{
    if (ui->pricist->text() == "0"){
        ui->pricist->setText("");
    }
    QString textik = ui->pricist->text();
    ui->pricist->setText(textik + "2");
}

void MainWindow::on_jedna_3_clicked()
{
    if (ui->pricist->text() == "0"){
        ui->pricist->setText("");
    }
    QString textik = ui->pricist->text();
    ui->pricist->setText(textik + "3");
}


void MainWindow::on_plus_clicked()
{
    QString main = ui->output->text();
    QString second = ui->pricist->text();

    int x = main.toInt() + second.toInt();

    ui->output->setText(QString::number(x));
}

