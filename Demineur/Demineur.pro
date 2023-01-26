TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

include(../MinGL/mingl.pri)

SOURCES += \
        grid.cpp \
        main.cpp

HEADERS += \
    cell.h \
    grid.h
