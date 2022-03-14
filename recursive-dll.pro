TEMPLATE = app
CONFIG += console c++17
QT += core
QT -= gui
DESTDIR = build

QMAKE_LFLAGS += "-Wl,-rpath,$$PWD/build"

SOURCES += \
		main.cpp \
		source.cpp \


HEADERS += \
		header.h \
        dll-lvl-1/header.h \
        dll-lvl-2/header.h \


LIBS += $$PWD/build/dll-lvl-1.so \
		$$PWD/build/dll-lvl-2.so \