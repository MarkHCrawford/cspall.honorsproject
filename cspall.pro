QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    db_connect.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    quiz.cpp \
    quizdb.cpp \
    signup.cpp

HEADERS += \
    db_connect.h \
    mainwindow.h \
    menu.h \
    quiz.h \
    quizdb.h \
    signup.h

FORMS += \
    mainwindow.ui \
    menu.ui \
    quiz.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
