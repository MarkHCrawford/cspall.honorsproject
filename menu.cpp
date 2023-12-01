#include "menu.h"
#include "ui_menu.h"
#include <db_connect.h>
#include <mainwindow.h>

menu::menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);

}

menu::~menu()
{
    delete ui;
}


void menu::on_logoutbutton_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    this->hide();
}

void menu::showdata(QString username)
{
    if(this->isActiveWindow())
    {
        menudb.set_username(username);
        userdata = menudb.get_user_data();
    }
    ui->profilefirstlabel->setText(userdata.firstname);
    ui->profilelastlabel->setText(userdata.lastname);
    ui->usernameprofilelabel->setText(userdata.username);
    ui->profiletext->setText(userdata.profile);
}
