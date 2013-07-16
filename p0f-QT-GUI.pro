#-------------------------------------------------
#
# Project created by QtCreator 2013-06-07T10:29:37
#
#-------------------------------------------------

QT       += core gui network

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
    tools/p0f-client.c \
    p0f_auditor.cpp \
    p0f_info.cpp \
    network_db.cpp \
    host.cpp \
    mythread.cpp

HEADERS  += guip0f.h \
    p0f.h \
    process.h \
    readfp.h \
    fp_tcp.h \
    fp_mtu.h \
    api.h \
    alloc-inl.h \
    types.h \
    tcp.h \
    languages.h \
    hash.h \
    fp_http.h \
    debug.h \
    config.h \
    p0f_auditor.h \
    p0f_info.h \
    network_db.h \
    host.h \
    mythread.h

FORMS    += guip0f.ui



LIBS += -lpcap

OTHER_FILES += \
    p0f.fp \
    windows.png \
    linux.jpg \
    dont_know.jpg \
    rete.jpg \
    mac.jpg

