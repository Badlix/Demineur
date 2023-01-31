TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

include(../MinGL/mingl.pri)

SOURCES += \
        game.cpp \
        grid.cpp \
        main.cpp \
    draw.cpp

HEADERS += \
    cell.h \
    game.h \
    grid.h \
    draw.h

DISTFILES += \
    ../Sprites
