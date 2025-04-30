#include "mainwindow.h"
#include "qmessagebox.h"
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


void MainWindow::on_pushButton_clicked()
{
    double promile = (ui->alkohol->value() * ui->procenta->value() * 0.8) / (ui->vaha->value() * 0.68) ;
    double strizliveni = promile / 0.15;

    QMessageBox boxik;
    QMessageBox::information(this, "promile", QString::number(promile) + "\n budes strizlivet: " + QString::number(strizliveni) + " h");

}

