#ifndef DB_CONNECT_H
#define DB_CONNECT_H

#include <QApplication>
#include <Qmainwindow.h>
#include <QTSql>

struct userData
{
    QString username, password, profile, firstname, lastname;
    int coursescompletecpp, coursescompletepython;
};



class opendatabase
{
    userData userdata;
    QString username;

public:
    QSqlDatabase db;
//constructor
    opendatabase();

//destructor : close database
    ~opendatabase();

//checks for existing user
    bool is_existing_user(QString username);

//user login database query, would not let me return count variable???
    int user_login(QString username, QString password);


//insert new user
    bool insert_user(QString username, QString password, QString profile, QString firstname, QString lastname);


//get user data from logged in user
    userData get_user_data();
    void set_username(QString username);
    QString get_username();
};





#endif // DB_CONNECT_H
