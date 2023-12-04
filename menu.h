#ifndef MENU_H
#define MENU_H
#include "db_connect.h"
#include "quizdb.h"
#include <QWidget>

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
    void showdata(QString username);

private slots:
    void on_logoutbutton_clicked();

    void on_startbutton_clicked();




    void on_languagedropdown_activated(int index);

private:
    Ui::menu *ui;
    userData userdata;
    opendatabase menudb;
    quizdb quizdatabase;
    int selected_course_num_complete;

};

#endif // MENU_H
