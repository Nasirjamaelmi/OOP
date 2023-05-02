    TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abstraktspelare.cpp \
        bankir.cpp \
        kort.cpp \
        korthand.cpp \
        kortlek.cpp \
        main.cpp \
        minafunktioner.cpp \
        spelare.cpp

HEADERS += \
    abstraktspelare.h \
    bankir.h \
    kort.h \
    korthand.h \
    kortlek.h \
    minafunktioner.h \
    spelare.h
