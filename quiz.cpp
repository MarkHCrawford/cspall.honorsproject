#include "quiz.h"
#include "ui_quiz.h"
#include "menu.h"
//for shuffling answers
#include "algorithm"
#include "quizdb.h"
#include "QDebug"
//holds questions and answers
#include "array"
#include "QMessageBox"


quiz::quiz(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::quiz)
{
    ui->setupUi(this);
}

quiz::~quiz()
{
    delete ui;
}


//called from menu
void quiz::setvars(QString course, QString difficulty)
{
    this->course = course;
    this->difficulty = difficulty;
    question_count = 0;
    quizdatabase.set_course_and_difficulty(course, difficulty);
    quizdatabase.pull_questions();
    qDebug() << quizdatabase.quiz_questions.at(0).question;
    get_question();
}

//load question
void quiz::get_question()
{
    randomize_options(quizdatabase.quiz_questions[question_count]);
    ui->questionbox->setText(quizdatabase.quiz_questions.at(question_count).question);
    ui->optionabutton->setText(question_options_random[0]);
    ui->optionbbutton->setText(question_options_random[1]);
    ui->optioncbutton->setText(question_options_random[2]);
    ui->optiondbutton->setText(question_options_random[3]);
    ui->getscorelabel->setText(QString::number(quizdatabase.get_score()));
}


//Pull answers and randomize choices
void quiz::randomize_options(questiondata current_option)
{
    question_options_random[0] = current_option.option_a;
    question_options_random[1] = current_option.option_b;
    question_options_random[2] = current_option.option_c;
    question_options_random[3] = current_option.answer;
    random_shuffle(question_options_random.begin(), question_options_random.end());

}


//run at end of quiz, tally score, did user pass
void quiz::end_of_quiz()
{
    if (quizdatabase.get_score() >= 7)
    {
        QMessageBox::about(this, "Congratulations", "You received a passing score!");
        quizdatabase.insert_new_score(username, course, courses_completed);
    }
    else
    {
        QMessageBox::about(this, "Try again", "You didn't receive a passing score, better luck next time!");
    }

    create_new_menu();
}

//create new menu object
void quiz::create_new_menu()
{
    menu *usermenu = new menu;
    usermenu->show();
    this->hide();
    usermenu->showdata(username);
}


//set username for menu continuity
void quiz::set_username(QString username)
{
    this->username = username;
}

//set courses completed
void quiz::set_courses_completed(int courses_completed)
{
    this->courses_completed = courses_completed;
}

//closing quiz ui and returning to menu
void quiz::on_exitbutton_clicked()
{
    create_new_menu();

}


//when user submits answer
void quiz::on_quizsubmitbutton_clicked()
{
//inform user that no options were selected
    if(!ui->optionabutton->isChecked() && !ui->optionbbutton->isChecked()
        && !ui->optioncbutton->isChecked() && !ui->optiondbutton->isChecked())
    {
        QMessageBox::about(this, "Warning", "No options were selected");
    }
    else if (ui->optionabutton->isChecked() && ui->optionabutton->text() == quizdatabase.quiz_questions.at(question_count).answer)
    {
        quizdatabase.add_score();
    }
    else if (ui->optionbbutton->isChecked() && ui->optionbbutton->text() == quizdatabase.quiz_questions.at(question_count).answer)
    {
        quizdatabase.add_score();
    }
    else if (ui->optioncbutton->isChecked() && ui->optioncbutton->text() == quizdatabase.quiz_questions.at(question_count).answer)
    {
        quizdatabase.add_score();
    }
    else if (ui->optiondbutton->isChecked() && ui->optiondbutton->text() == quizdatabase.quiz_questions.at(question_count).answer)
    {
        quizdatabase.add_score();
    }
    else
    {
        QMessageBox::about(this, "Wrong answer","The correct answer is: " +
                                                     quizdatabase.quiz_questions.at(question_count).answer);
    }

    //go to next question
    question_count++;

    //check if last question
    if (question_count == 9)
    {
        end_of_quiz();
    }
    else
    {
        get_question();
    }

}

