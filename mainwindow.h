#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QtSql>
#include <db_connect.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    opendatabase mydb;


private slots:
    void on_loginbutton_clicked();

    void on_signup_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
