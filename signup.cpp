#include "signup.h"
#include "ui_signup.h"
#include "QApplication"
#include <db_connect.h>



signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
    this->setWindowTitle("Signup");

}

signup::~signup()
{
    delete ui;
}

void signup::on_cancelbutton_clicked()
{
    this->close();
}


void signup::on_submitbutton_clicked()
{
    QString username, password, profile, firstname, lastname;
    username = ui->usernamesignup->text();
    password = ui->passwordsignup->text();
    profile = ui->profilesignup->toPlainText();
    firstname = ui->firstnamesignup->text();
    lastname = ui->lastnamesignup->text();

    bool successful_account = signupdb.insert_user(username, password, profile, firstname, lastname);
    if(successful_account)
    {
        this->close();

    }
    else
    {
        ui->accountcreationmessage->setText("Error creating account, username already taken.");
    }
}

