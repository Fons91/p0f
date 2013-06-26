#-------------------------------------------------
#
# Project created by QtCreator 2013-06-07T10:29:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = p0f-QT-GUI
TEMPLATE = app


SOURCES += main.cpp\
        guip0f.cpp \
    p0f.c \
    process.c \
    readfp.c \
    fp_tcp.c \
    fp_mtu.c \
    fp_http.c \
    api.c \
    tools/p0f-sendsyn6.c \
    tools/p0f-sendsyn.c \
    tools/p0f-client.c

HEADERS  += guip0f.h \
    p0f.h \
    process.h \
    readfp.h \
    fp_tcp.h \
    fp_mtu.h \
    fp_http. \
    api.h \
    tools/p0f-sendsyn6.h \
    tools/p0f-sendsyn.h \
    tools/p0f-client.h \
    alloc-inl.h \
    types.h \
    tcp.h \
    languages.h \
    hash.h \
    fp_http.h \
    debug.h \
    config.h

FORMS    += guip0f.ui



LIBS += -lpcap

