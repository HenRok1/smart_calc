/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result_show;
    QPushButton *pushButton_0;
    QPushButton *pushButton_1;
    QPushButton *pushButton_5;
    QPushButton *pushButton_ravno;
    QPushButton *pushButton_clean;
    QPushButton *pushButton_4;
    QPushButton *pushButton_skobki;
    QPushButton *pushButton_unar_min;
    QPushButton *pushButton_7;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_2;
    QPushButton *pushButton_del;
    QPushButton *pushButton_8;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_6;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_log;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_step;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(435, 410);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        result_show = new QLabel(centralwidget);
        result_show->setObjectName("result_show");
        result_show->setGeometry(QRect(10, 10, 411, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Dubai")});
        font.setPointSize(20);
        result_show->setFont(font);
        result_show->setStyleSheet(QString::fromUtf8("color: #FFCC66;\n"
"QLabel {\n"
"  qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"  border: 1px solid gray;\n"
"}"));
        result_show->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(230, 340, 60, 60));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Dubai")});
        font1.setPointSize(25);
        font1.setBold(false);
        font1.setItalic(false);
        pushButton_0->setFont(font1);
        pushButton_0->setLayoutDirection(Qt::LeftToRight);
        pushButton_0->setAutoFillBackground(false);
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(160, 270, 60, 60));
        pushButton_1->setFont(font1);
        pushButton_1->setLayoutDirection(Qt::LeftToRight);
        pushButton_1->setAutoFillBackground(false);
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(230, 200, 60, 60));
        pushButton_5->setFont(font1);
        pushButton_5->setLayoutDirection(Qt::LeftToRight);
        pushButton_5->setAutoFillBackground(false);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_ravno = new QPushButton(centralwidget);
        pushButton_ravno->setObjectName("pushButton_ravno");
        pushButton_ravno->setGeometry(QRect(370, 340, 60, 60));
        pushButton_ravno->setFont(font1);
        pushButton_ravno->setLayoutDirection(Qt::LeftToRight);
        pushButton_ravno->setAutoFillBackground(false);
        pushButton_ravno->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #333333;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #00FFFF;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_clean = new QPushButton(centralwidget);
        pushButton_clean->setObjectName("pushButton_clean");
        pushButton_clean->setGeometry(QRect(160, 60, 60, 60));
        pushButton_clean->setFont(font1);
        pushButton_clean->setLayoutDirection(Qt::LeftToRight);
        pushButton_clean->setAutoFillBackground(false);
        pushButton_clean->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(170, 0, 0);\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(160, 200, 60, 60));
        pushButton_4->setFont(font1);
        pushButton_4->setLayoutDirection(Qt::LeftToRight);
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_skobki = new QPushButton(centralwidget);
        pushButton_skobki->setObjectName("pushButton_skobki");
        pushButton_skobki->setGeometry(QRect(230, 60, 60, 60));
        pushButton_skobki->setFont(font1);
        pushButton_skobki->setLayoutDirection(Qt::LeftToRight);
        pushButton_skobki->setAutoFillBackground(false);
        pushButton_skobki->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #00FFFF;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_unar_min = new QPushButton(centralwidget);
        pushButton_unar_min->setObjectName("pushButton_unar_min");
        pushButton_unar_min->setGeometry(QRect(160, 340, 60, 60));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Dubai")});
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        pushButton_unar_min->setFont(font2);
        pushButton_unar_min->setLayoutDirection(Qt::LeftToRight);
        pushButton_unar_min->setAutoFillBackground(false);
        pushButton_unar_min->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 20pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(160, 130, 60, 60));
        pushButton_7->setFont(font1);
        pushButton_7->setLayoutDirection(Qt::LeftToRight);
        pushButton_7->setAutoFillBackground(false);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName("pushButton_mult");
        pushButton_mult->setGeometry(QRect(370, 130, 60, 60));
        pushButton_mult->setFont(font1);
        pushButton_mult->setLayoutDirection(Qt::LeftToRight);
        pushButton_mult->setAutoFillBackground(false);
        pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #00FFFF;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(300, 340, 60, 60));
        pushButton_dot->setFont(font1);
        pushButton_dot->setLayoutDirection(Qt::LeftToRight);
        pushButton_dot->setAutoFillBackground(false);
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(230, 270, 60, 60));
        pushButton_2->setFont(font1);
        pushButton_2->setLayoutDirection(Qt::LeftToRight);
        pushButton_2->setAutoFillBackground(false);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_del = new QPushButton(centralwidget);
        pushButton_del->setObjectName("pushButton_del");
        pushButton_del->setGeometry(QRect(370, 60, 60, 60));
        pushButton_del->setFont(font1);
        pushButton_del->setLayoutDirection(Qt::LeftToRight);
        pushButton_del->setAutoFillBackground(false);
        pushButton_del->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #00FFFF;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(230, 130, 60, 60));
        pushButton_8->setFont(font1);
        pushButton_8->setLayoutDirection(Qt::LeftToRight);
        pushButton_8->setAutoFillBackground(false);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(370, 200, 60, 60));
        pushButton_minus->setFont(font1);
        pushButton_minus->setLayoutDirection(Qt::LeftToRight);
        pushButton_minus->setAutoFillBackground(false);
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #00FFFF;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(300, 130, 60, 60));
        pushButton_9->setFont(font1);
        pushButton_9->setLayoutDirection(Qt::LeftToRight);
        pushButton_9->setAutoFillBackground(false);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(300, 270, 60, 60));
        pushButton_3->setFont(font1);
        pushButton_3->setLayoutDirection(Qt::LeftToRight);
        pushButton_3->setAutoFillBackground(false);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(370, 270, 60, 60));
        pushButton_plus->setFont(font1);
        pushButton_plus->setLayoutDirection(Qt::LeftToRight);
        pushButton_plus->setAutoFillBackground(false);
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #00FFFF;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(300, 200, 60, 60));
        pushButton_6->setFont(font1);
        pushButton_6->setLayoutDirection(Qt::LeftToRight);
        pushButton_6->setAutoFillBackground(false);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFFF99;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(300, 60, 60, 60));
        pushButton_mod->setFont(font1);
        pushButton_mod->setLayoutDirection(Qt::LeftToRight);
        pushButton_mod->setAutoFillBackground(false);
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #00FFFF;\n"
"	border: 2px solid #0;\n"
"	font: 25pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(10, 200, 60, 60));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Dubai")});
        font3.setPointSize(18);
        font3.setBold(false);
        font3.setItalic(false);
        pushButton_sqrt->setFont(font3);
        pushButton_sqrt->setLayoutDirection(Qt::LeftToRight);
        pushButton_sqrt->setAutoFillBackground(false);
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 18pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName("pushButton_log");
        pushButton_log->setGeometry(QRect(10, 60, 60, 60));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Dubai")});
        font4.setPointSize(22);
        font4.setBold(false);
        font4.setItalic(false);
        pushButton_log->setFont(font4);
        pushButton_log->setLayoutDirection(Qt::LeftToRight);
        pushButton_log->setAutoFillBackground(false);
        pushButton_log->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 22pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(80, 130, 60, 60));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Dubai")});
        font5.setPointSize(16);
        font5.setBold(false);
        font5.setItalic(false);
        pushButton_asin->setFont(font5);
        pushButton_asin->setLayoutDirection(Qt::LeftToRight);
        pushButton_asin->setAutoFillBackground(false);
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 16pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(80, 60, 60, 60));
        pushButton_tan->setFont(font4);
        pushButton_tan->setLayoutDirection(Qt::LeftToRight);
        pushButton_tan->setAutoFillBackground(false);
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 22pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(80, 200, 60, 60));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Dubai")});
        font6.setPointSize(15);
        font6.setBold(false);
        font6.setItalic(false);
        pushButton_acos->setFont(font6);
        pushButton_acos->setLayoutDirection(Qt::LeftToRight);
        pushButton_acos->setAutoFillBackground(false);
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 15pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(80, 270, 60, 60));
        pushButton_atan->setFont(font6);
        pushButton_atan->setLayoutDirection(Qt::LeftToRight);
        pushButton_atan->setAutoFillBackground(false);
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 15pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(10, 270, 60, 60));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Dubai")});
        font7.setPointSize(21);
        font7.setBold(false);
        font7.setItalic(false);
        pushButton_sin->setFont(font7);
        pushButton_sin->setLayoutDirection(Qt::LeftToRight);
        pushButton_sin->setAutoFillBackground(false);
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 21pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setGeometry(QRect(10, 340, 60, 60));
        pushButton_cos->setFont(font7);
        pushButton_cos->setLayoutDirection(Qt::LeftToRight);
        pushButton_cos->setAutoFillBackground(false);
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 21pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(10, 130, 60, 60));
        pushButton_ln->setFont(font4);
        pushButton_ln->setLayoutDirection(Qt::LeftToRight);
        pushButton_ln->setAutoFillBackground(false);
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 22pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        pushButton_step = new QPushButton(centralwidget);
        pushButton_step->setObjectName("pushButton_step");
        pushButton_step->setGeometry(QRect(80, 340, 60, 60));
        pushButton_step->setFont(font7);
        pushButton_step->setLayoutDirection(Qt::LeftToRight);
        pushButton_step->setAutoFillBackground(false);
        pushButton_step->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #FFCC66;\n"
"	border: 2px solid #0;\n"
"	font: 21pt \"Dubai\";\n"
"	border-radius: 30px;\n"
"	border-style: outset;\n"
"	background: #333333;\n"
"	padding: 7px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color:  #999999;\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result_show->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_ravno->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_clean->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_skobki->setText(QCoreApplication::translate("MainWindow", "()", nullptr));
        pushButton_unar_min->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_step->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
