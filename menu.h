#ifndef MENU_H
#define MENU_H

#include "db_connect.h"
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

private:
    Ui::menu *ui;
    userData userdata;
    opendatabase menudb;
};

#endif // MENU_H
