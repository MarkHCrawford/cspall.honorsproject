#ifndef QUIZDB_H
#define QUIZDB_H

#include <QApplication>
#include <QTSql>
#include <array>
using namespace std;
//struct used for the quiz questions pulled from database
struct questiondata
{
    QString question, option_a, option_b, option_c, answer;
};


class quizdb
{
public:
    quizdb();
    ~quizdb();
//get questions from db
    void pull_questions();
//make a dector of quiz questions
    array<questiondata, 10> quiz_questions;
    questiondata question_in;
//set course and difficulty from "go" button and dropdowns on menu ui
    void set_course_and_difficulty(QString course, QString difficulty);
//add score
    void add_score();
//get score
    int get_score();
//update database with new course completed
    void insert_new_score(QString username, QString course, int coursescompleted);

private:
    QString course;
    QString difficulty;
    int score = 0;
    QSqlDatabase db;

};

#endif // QUIZDB_H
