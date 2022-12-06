#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

qt += sql
QT       += core gui sql
QT += printsupport
QT += widgets multimedia
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app
QT += charts
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


CONFIG += c++11

SOURCES += \
    arduino.cpp \
    fournisseur.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    mimeattachment.cpp \
    mimebase64encoder.cpp \
    mimebase64formatter.cpp \
    mimebytearrayattachment.cpp \
    mimecontentencoder.cpp \
    mimecontentformatter.cpp \
    mimefile.cpp \
    mimehtml.cpp \
    mimeinlinefile.cpp \
    mimemessage.cpp \
    mimepart.cpp \
    mimeqpencoder.cpp \
    mimeqpformatter.cpp \
    mimetext.cpp \
    quotedprintable.cpp \
    smtp.cpp \
    smtpclient.cpp

HEADERS += \
    SmtpMime \
    arduino.h \
    fournisseur.h \
        mainwindow.h \
    connection.h \
    mimeattachment.h \
    mimebase64encoder.h \
    mimebase64formatter.h \
    mimebytearrayattachment.h \
    mimecontentencoder.h \
    mimecontentformatter.h \
    mimefile.h \
    mimehtml.h \
    mimeinlinefile.h \
    mimemessage.h \
    mimemultipart.h \
    mimepart.h \
    mimeqpencoder.h \
    mimeqpformatter.h \
    mimetext.h \
    quotedprintable.h \
    smtp.h \
    smtpclient.h \
    smtpmime_global.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Atelier_Connexion.pro.user \
    Atelier_Connexion.pro.user.d567f1b.4.8-pre1
