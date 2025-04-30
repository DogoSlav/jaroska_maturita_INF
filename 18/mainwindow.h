#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionO_programu_triggered();

    void on_actionVyjmout_triggered();

    void on_actionKopirovat_triggered();

    void on_actionVlozit_triggered();

    void on_actionNovy_triggered();

    void on_actionOtevrit_triggered();

    void on_actionUlozit_jako_triggered();

    void on_actionKonec_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
