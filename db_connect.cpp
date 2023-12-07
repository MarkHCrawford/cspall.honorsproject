#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <db_connect.h>


//opening and using database


opendatabase::opendatabase()
{

//set database object, database type, database name (local storage for now)
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\Ender Crowing\\Documents\\sqlite\\cspall");
//exception handling when opening database
    if (!db.open()){throw "Error opening database";}
    try
    {
        db.open();
        qDebug() << "Database connected." << Qt::endl;
    }
    catch (const QString errormsg)
    {
        qDebug() << "Error: " + errormsg << Qt::endl;
        qDebug() << db.lastError() << Qt::endl;
    }


}

//close db on object destruction
opendatabase::~opendatabase(){db.close();}



//on login, does user exist?
bool opendatabase::is_existing_user(QString username)
{
    int user_count = 0;
    QSqlQuery username_query;
    if (username_query.exec("select * from user where username='"+username+"'"))
    {
        while(username_query.next())
        {
            user_count++;
        }

    }
    return (user_count == 0) ? false : true;
}




//user login database query, would not let me return count variable???
int opendatabase::user_login(QString username, QString password)
{
    QSqlQuery userquery;
    if (userquery.exec("select * from user where username='"+username+"' and password='"+password+"'"))
    {
        int count = 0;
        while(userquery.next())
        {
            count++;
        }
        if (count == 1)
            return 1;
        if (count > 1)
            return 2;
        if (count < 1)
            return 0;
    }
    this->username = username;
    return 0;
}


//add new user to database
bool opendatabase::insert_user(QString username, QString password, QString profile, QString firstname, QString lastname)
{

//check if user already exists
    if(is_existing_user(username)){return false;}

//increment id number of user
    int max_id_num = 0;
    QSqlQuery max_id;
    max_id.exec("select id from user");
    while (max_id.next()) {
        max_id_num = max_id.value(0).toInt();
    }
    max_id_num++;


 //create new user
    QSqlQuery create_user;
    create_user.prepare("insert into user ("
                       "id, "
                       "username, "
                       "password, "
                       "profile, "
                       "firstname, "
                       "lastname, "
                       "coursescompletecpp, "
                        "coursescompletepython)"
                       "values (?,?,?,?,?,?,?,?)");
    create_user.addBindValue(max_id_num);
    create_user.addBindValue(username);
    create_user.addBindValue(password);
    create_user.addBindValue(profile);
    create_user.addBindValue(firstname);
    create_user.addBindValue(lastname);
    create_user.addBindValue(0);
    create_user.addBindValue(0);
    create_user.exec();
    return true;
}

//get userdata for menu
userData opendatabase::get_user_data()
{
    QSqlQuery get_user_data;
    if(get_user_data.exec("select * from user where username='"+username+"'"))
    {
        while(get_user_data.next())
        {
            userdata.username = get_user_data.value(1).toString();
            userdata.profile = get_user_data.value(3).toString();
            userdata.firstname = get_user_data.value(4).toString();
            userdata.lastname = get_user_data.value(5).toString();
            userdata.coursescompletecpp = get_user_data.value(6).toInt();
            userdata.coursescompletepython = get_user_data.value(7).toInt();
        }
     }
    return userdata;
}


void opendatabase::set_username(QString username){this->username = username; }


QString opendatabase::get_username()
{
    return username;
}
