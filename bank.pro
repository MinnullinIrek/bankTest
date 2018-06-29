TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cashbox.cpp \
    db.cpp \
    bank.cpp \
    io.cpp \
    parser.cpp

HEADERS += \
    cashbox.h \
    db.h \
    bank.h \
    io.h \
    parser.h \
    operation.h
