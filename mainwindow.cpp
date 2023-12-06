#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <db_connect.h>
#include "signup.h"
#include "menu.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//title of window
    this->setWindowTitle("CSPall Login");
//load images onto labels using pixmap
    QPixmap pm("C:\\Users\\Ender Crowing\\Documents\\cspall\\icons8-c++-96.png");
    QPixmap pm2("C:\\Users\\Ender Crowing\\Documents\\cspall\\icons8-python-96.png");
    ui->label_3->setPixmap(pm);
    ui->label->setPixmap(pm2);
    ui->label_3->setScaledContents(true);
    ui->label->setScaledContents(true);


}


MainWindow::~MainWindow()
{
    delete ui;
}


//login button event
void MainWindow::on_loginbutton_clicked()
{

// get username and password from line-edit when button is clicked
    QString username, password;
    username = ui->username->text();
    password = ui->password->text();
    int count = mydb.user_login(username, password);
    if (count == 1)
    {
 //when login successful show menu window and show userdata on menu window
        ui->loginmessagelabel->setText("Successful login");
        menu *usermenu = new menu;
        usermenu->show();
        this->hide();
        usermenu->showdata(username);
    }
    else if (count > 1)
        ui->loginmessagelabel->setText("Duplicate username and password");
    else if (count < 1)
        ui->loginmessagelabel->setText("Incorrect password.");
}


//go to signup window
void MainWindow::on_signup_clicked()
{
    signup signupwin;
    signupwin.setModal(true);
    signupwin.exec();

}

