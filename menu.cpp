#include "menu.h"
#include "ui_menu.h"
#include "quiz.h"
#include <db_connect.h>
#include <mainwindow.h>
#include <quizdb.h>

menu::menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    this->setWindowTitle("CSPall");
}

menu::~menu()
{
    delete ui;
}

//go back to login if logout clicked
void menu::on_logoutbutton_clicked()
{
    MainWindow *win = new MainWindow;
    win->show();
    this->hide();
}


//show user data on main menu: username, first, last, default course, default courses completed
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
    ui->courselabel->setText(ui->languagedropdown->currentText());
    if (ui->languagedropdown->currentText() == "python")
    {
        ui->coursescompletelabel->setText(QString::number(userdata.coursescompletepython));
        selected_course_num_complete = userdata.coursescompletepython;
    }
    else
    {
        ui->coursescompletelabel->setText(QString::number(userdata.coursescompletecpp));
        selected_course_num_complete = userdata.coursescompletecpp;
    }
}

//start quiz
void menu::on_startbutton_clicked()
{
    QString course = ui->languagedropdown->currentText();
    QString difficulty = ui->difficultydropdown->currentText();
    quiz *quizwin = new quiz;
    quizwin->show();
    quizwin->setvars(course, difficulty);
    quizwin->set_username(userdata.username);
    quizwin->set_courses_completed(selected_course_num_complete);
    this->hide();
    if (quizwin->isHidden()){this->show();}
}








//update labels with course and course completed number when dropdown changed
void menu::on_languagedropdown_activated(int index)
{
    if (index == 0)
    {
        ui->courselabel->setText("cpp");
        ui->coursescompletelabel->setText(QString::number(userdata.coursescompletecpp));
        selected_course_num_complete = userdata.coursescompletepython;
    }
    else if (index == 1)
    {
        ui->courselabel->setText("python");
        ui->coursescompletelabel->setText(QString::number(userdata.coursescompletepython));
        selected_course_num_complete = userdata.coursescompletecpp;
    }
}

