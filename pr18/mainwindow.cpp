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


void MainWindow::on_actionO_programu_triggered()
{
    QMessageBox::about(this, "O programu", "Tun tun tun tun tun sahur v. 3.11");
}


void MainWindow::on_actionVyjmout_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionKopirovat_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionVlozit_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionNovy_triggered()
{
    ui->textEdit->clear();
}


void MainWindow::on_actionOtevrit_triggered()
{
    QFileDialog xd;
    QString jmenoSouboru = xd.getOpenFileName();

    QFile file(jmenoSouboru);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&file);
    QString textik = in.readAll();
    ui->textEdit->setText(textik);
    file.close();
}


void MainWindow::on_actionUlozit_jako_triggered()
{
    QFileDialog xd;
    QString jmenoSouboru = xd.getSaveFileName();

    QFile file(jmenoSouboru);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream out(&file);

    QString textik = ui->textEdit->toPlainText();
    out << textik;

    file.close();
}


void MainWindow::on_actionKonec_triggered()
{
    this->close();
}

