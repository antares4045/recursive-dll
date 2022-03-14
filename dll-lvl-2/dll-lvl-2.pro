TEMPLATE = lib

QT -= gui
CONFIG += no_plugin_name_prefix
CONFIG += plugin


QMAKE_LFLAGS += "-Wl,-rpath,$$PWD/../build"

CONFIG += dll

DESTDIR = ../build

HEADERS += \
		../dll-lvl-1/header.h \

LIBS += $$PWD/../build/dll-lvl-1.so
