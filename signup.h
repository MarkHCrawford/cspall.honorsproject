#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <db_connect.h>


namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();
    opendatabase signupdb;

private slots:
    void on_cancelbutton_clicked();

    void on_submitbutton_clicked();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
