QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    calculator.cpp \
    ../s21_SmartCalc.c \
    graph.cpp \
    qcustomplot.cpp \
    ../s21_bonusPart.c

HEADERS += \
    calculator.h \
    graph.h \
    qcustomplot.h \
    ../s21_SmartCalc.h \
    ../s21_bonusPart.h

FORMS += \
    calculator.ui \
    graph.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
