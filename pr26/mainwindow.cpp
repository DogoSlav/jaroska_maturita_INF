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


void MainWindow::on_actionOpen_triggered()
{

    QFileDialog xd;
    QString jmeno = xd.getOpenFileName();

    QMessageBox::information(this, "Co bylo vybrano", jmeno);
}


void MainWindow::on_actionSave_triggered()
{
    QFileDialog xd;
    xd.getSaveFileName();
}


void MainWindow::on_actionQuestion_triggered()
{
    // ano = 0, ne = 1;
    int co = QMessageBox::question(this, "Dotaz", "uz je ti horko? xd", "ano", "ne");

    QMessageBox::information(this, "Co bylo zvoleno", ((co) ? "ne" : "ano"));
}


void MainWindow::on_actionInformation_triggered()
{
    QMessageBox::information(this, "Informace", "I hate...");
}


void MainWindow::on_actiongetDouble_triggered()
{
    double x = QInputDialog::getDouble(this, "nadpis", "lorem ipsum");

    QMessageBox::information(this, "Co bylo zadano", "lol: " + QString::number(x));

}

