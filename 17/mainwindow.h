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

private slots:
    void on_nuluj_out_clicked();

    void on_nuluj_add_clicked();

    void on_jedna_clicked();

    void on_jedna_2_clicked();

    void on_jedna_3_clicked();

    void on_plus_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
