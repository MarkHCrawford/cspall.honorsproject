#include "mainwindow.h"
#include <QApplication>
#include <db_connect.h>
#include <QFile>

int main(int argc, char *argv[])
{
//loading open source stylesheet
    QFile stylesheetload("C:\\Users\\Ender Crowing\\Documents\\cspall\\Combinear.qss");
    stylesheetload.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(stylesheetload.readAll());

    QApplication a(argc, argv);
//apply loaded stylesheet
    a.setStyleSheet(stylesheet);
    MainWindow w;
    w.show();
    stylesheetload.close();
    return a.exec();
}
