TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    longint.h


QMAKE_CXXFLAGS += -std=gnu++11
