#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include <quizdb.h>
#include <array>
#include "quizdb.h"

namespace Ui {
class quiz;
}

class quiz : public QWidget
{
    Q_OBJECT

public:
    explicit quiz(QWidget *parent = nullptr);
    ~quiz();
//set course and difficulty when opening from menu
    void setvars(QString course, QString difficulty);
//get first question
    void get_question();
 //randomize the choices
    void randomize_options(questiondata current_question);
 //end of quiz results
    void end_of_quiz();
//create new menu object
    void create_new_menu();
//set username
    void set_username(QString username);
//set courses completed
    void set_courses_completed(int courses_completed);

private slots:
    void on_exitbutton_clicked();

    void on_quizsubmitbutton_clicked();

private:
    Ui::quiz *ui;
    QString course;
    QString difficulty;
    QString username;
    quizdb quizdatabase;
    int question_count;
    int courses_completed;
    std::array<QString, 4> question_options_random;
};

#endif // QUIZ_H
