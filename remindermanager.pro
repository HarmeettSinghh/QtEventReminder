QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ReminderManager
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    remindermanager.cpp \
    workerthread.cpp \
    event.cpp

HEADERS += \
    mainwindow.h \
    remindermanager.h \
    workerthread.h \
    event.h

FORMS += \
    mainwindow.ui
