#include "quizdb.h"
#include "array"
#include "QSqlQuery"
#include "QDebug"

//constructor, call parent object to ensure db is open
quizdb::quizdb() : opendatabase(){
    score = 0;}

quizdb::~quizdb(){}


//pull questions from database
void quizdb::pull_questions()
{
    int count = 0;
    QSqlQuery question_query;
    if(question_query.exec("select * from content where course='"+course+"' and difficulty='"+difficulty+"'"))
    {
        while(question_query.next())
        {

            quiz_questions[count].question = question_query.value(3).toString();
            quiz_questions[count].option_a = question_query.value(4).toString();
            quiz_questions[count].option_b = question_query.value(5).toString();
            quiz_questions[count].option_c = question_query.value(6).toString();
            quiz_questions[count].answer = question_query.value(7).toString();
            count++;
        }
    }

}

//get course and difficulty from menu ui
void quizdb::set_course_and_difficulty(QString course, QString difficulty)
{
    this->course = course;
    this->difficulty = difficulty;
}

//add score
void quizdb::add_score(){score++;}

//get score
int quizdb::get_score(){return score;}


//update table with course completed
void quizdb::insert_new_score(QString username, QString course, int coursescompleted)
{
    coursescompleted++;
    QString course_table_name = (course == "python") ? "coursescompletepython" : "coursescompletecpp";
    QSqlQuery course_score;

    course_score.prepare("update user set '"+course_table_name+"'='"+QString::number(coursescompleted)+"' where username='"+username+"'");
    course_score.exec();
}
