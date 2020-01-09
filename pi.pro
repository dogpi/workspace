TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/camera.cpp \
        src/main.cpp

HEADERS += \
    include/camera.h

INCLUDEPATH += /usr/local/include \
               /usr/local/include/opencv \
               /usr/local/include/opencv2


LIBS += /usr/local/lib/*.so
LIBS += -lpthread
