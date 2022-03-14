TEMPLATE = lib

QT -= gui
CONFIG += no_plugin_name_prefix
CONFIG += plugin

CONFIG += dll

DESTDIR = ../build

HEADERS += \
		header.h \

SOURCES += \
	source.cpp
