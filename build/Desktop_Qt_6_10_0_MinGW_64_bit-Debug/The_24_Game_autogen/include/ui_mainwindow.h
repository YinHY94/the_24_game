/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_main;
    QFrame *frameTop;
    QHBoxLayout *horizontalLayout_top;
    QLabel *labelLogo;
    QPushButton *ruleBtn;
    QPushButton *rankBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *labelUser;
    QPushButton *logoutBtn;
    QStackedWidget *stackedWidget;
    QWidget *pageWelcome;
    QVBoxLayout *verticalLayout_welcome;
    QSpacerItem *verticalSpacer_Top;
    QLabel *labelTitle;
    QSpacerItem *verticalSpacer;
    QPushButton *loginBtn;
    QPushButton *registerBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(862, 532);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    /* * \345\205\250\345\261\200\346\267\261\350\211\262\344\270\273\351\242\230 \n"
"     * Background: #282C34 (\346\267\261\347\201\260\350\223\235)\n"
"     * Accent: #00BCD4 (\347\247\221\346\212\200\351\235\222\350\211\262)\n"
"    */\n"
"    QMainWindow { \n"
"     background: #282C34; \n"
"     color: #F0F0F0;\n"
"    }\n"
"    \n"
"    /* \351\241\266\351\203\250\346\240\217\351\200\232\347\224\250\346\214\211\351\222\256\346\240\267\345\274\217: \347\256\200\346\264\201\347\231\275\350\211\262/\346\202\254\345\201\234\345\217\230\350\211\262 */\n"
"    QFrame#frameTop QPushButton {\n"
"    	background: transparent;\n"
"    	color: #F0F0F0;\n"
"    	font-weight: bold;\n"
"    	font-size: 14px;\n"
"    	border: none;\n"
"    	border-radius: 6px;\n"
"    	padding: 8px 12px;\n"
"    }\n"
"    QFrame#frameTop QPushButton:hover {\n"
"    	background: rgba(0, 188, 212, 0.2); /* \351\235\222\350\211\262\346\202\254\345\201\234 */\n"
"    }\n"
"    QFrame#frameTop QPushButton:pressed {\n"
"    	backgrou"
                        "nd: rgba(0, 188, 212, 0.4); \n"
"    }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_main = new QVBoxLayout(centralwidget);
        verticalLayout_main->setSpacing(0);
        verticalLayout_main->setObjectName("verticalLayout_main");
        verticalLayout_main->setContentsMargins(0, 0, 0, 0);
        frameTop = new QFrame(centralwidget);
        frameTop->setObjectName("frameTop");
        frameTop->setMinimumSize(QSize(0, 70));
        frameTop->setStyleSheet(QString::fromUtf8("\n"
"        QFrame#frameTop {\n"
"         background: #20232A; /* \347\225\245\346\267\261\347\232\204\351\241\266\351\203\250\346\240\217\350\203\214\346\231\257 */\n"
"         border-bottom: 1px solid #00BCD4; /* \345\272\225\351\203\250\345\274\272\350\260\203\347\272\277 */\n"
"        }\n"
"       "));
        horizontalLayout_top = new QHBoxLayout(frameTop);
        horizontalLayout_top->setSpacing(10);
        horizontalLayout_top->setObjectName("horizontalLayout_top");
        horizontalLayout_top->setContentsMargins(24, 0, 24, 0);
        labelLogo = new QLabel(frameTop);
        labelLogo->setObjectName("labelLogo");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        labelLogo->setFont(font);
        labelLogo->setStyleSheet(QString::fromUtf8("color: #00BCD4; background: transparent;"));

        horizontalLayout_top->addWidget(labelLogo);

        ruleBtn = new QPushButton(frameTop);
        ruleBtn->setObjectName("ruleBtn");

        horizontalLayout_top->addWidget(ruleBtn);

        rankBtn = new QPushButton(frameTop);
        rankBtn->setObjectName("rankBtn");

        horizontalLayout_top->addWidget(rankBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_top->addItem(horizontalSpacer);

        labelUser = new QLabel(frameTop);
        labelUser->setObjectName("labelUser");
        QFont font1;
        font1.setPointSize(11);
        labelUser->setFont(font1);
        labelUser->setStyleSheet(QString::fromUtf8("color: #AAAAAA; background: transparent;"));

        horizontalLayout_top->addWidget(labelUser);

        logoutBtn = new QPushButton(frameTop);
        logoutBtn->setObjectName("logoutBtn");
        logoutBtn->setMinimumSize(QSize(80, 32));
        logoutBtn->setVisible(false);
        logoutBtn->setStyleSheet(QString::fromUtf8("\n"
"           QPushButton {\n"
"           	background: transparent;\n"
"           	color: #F0F0F0;\n"
"           	border: 1px solid #777777; /* \347\201\260\350\211\262\350\276\271\346\241\206 */\n"
"           	border-radius: 6px;\n"
"           	padding: 0px 12px;\n"
"            font-weight: bold;\n"
"           }\n"
"           QPushButton:hover { \n"
"            background: rgba(0, 188, 212, 0.2); \n"
"            border: 1px solid #00BCD4; /* \346\202\254\345\201\234\346\227\266\345\274\272\350\260\203\350\211\262\350\276\271\346\241\206 */\n"
"           }\n"
"          "));

        horizontalLayout_top->addWidget(logoutBtn);


        verticalLayout_main->addWidget(frameTop);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background: transparent;"));
        pageWelcome = new QWidget();
        pageWelcome->setObjectName("pageWelcome");
        verticalLayout_welcome = new QVBoxLayout(pageWelcome);
        verticalLayout_welcome->setSpacing(16);
        verticalLayout_welcome->setObjectName("verticalLayout_welcome");
        verticalLayout_welcome->setContentsMargins(40, 40, 40, 40);
        verticalSpacer_Top = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_welcome->addItem(verticalSpacer_Top);

        labelTitle = new QLabel(pageWelcome);
        labelTitle->setObjectName("labelTitle");
        QFont font2;
        font2.setPointSize(28);
        font2.setBold(true);
        labelTitle->setFont(font2);
        labelTitle->setStyleSheet(QString::fromUtf8("color: #F0F0F0;"));
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_welcome->addWidget(labelTitle);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_welcome->addItem(verticalSpacer);

        loginBtn = new QPushButton(pageWelcome);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setMinimumSize(QSize(220, 56));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        loginBtn->setFont(font3);
        loginBtn->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"            	background: #00BCD4; /* \345\274\272\350\260\203\350\211\262 */\n"
"            	color: #1E1E1E; /* \346\267\261\350\211\262\346\226\207\346\234\254\357\274\214\351\253\230\345\257\271\346\257\224\345\272\246 */\n"
"            	border: none;\n"
"            	border-radius: 12px;\n"
"            }\n"
"            QPushButton:hover {\n"
"            	background: #00E5FF; /* \347\225\245\344\272\256\347\232\204\345\274\272\350\260\203\350\211\262 */\n"
"            }\n"
"           "));

        verticalLayout_welcome->addWidget(loginBtn);

        registerBtn = new QPushButton(pageWelcome);
        registerBtn->setObjectName("registerBtn");
        registerBtn->setMinimumSize(QSize(0, 0));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        registerBtn->setFont(font4);
        registerBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        registerBtn->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"            	color: #00BCD4; /* \345\274\272\350\260\203\350\211\262 */\n"
"            	background: transparent;\n"
"            	border: none;\n"
"            	padding: 8px 16px;\n"
"            	border-radius: 6px;\n"
"            }\n"
"            QPushButton:hover {\n"
"            	background: rgba(0, 188, 212, 0.15); /* \346\237\224\345\222\214\346\202\254\345\201\234 */\n"
"            	color: #00E5FF;\n"
"            }\n"
"            QPushButton:pressed {\n"
"            	background: rgba(0, 188, 212, 0.3);\n"
"            }\n"
"           "));
        registerBtn->setFlat(true);

        verticalLayout_welcome->addWidget(registerBtn);

        stackedWidget->addWidget(pageWelcome);

        verticalLayout_main->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "24\347\202\271\346\270\270\346\210\217\344\270\255\345\277\203 - \346\267\261\350\211\262\346\250\241\345\274\217", nullptr));
        labelLogo->setText(QCoreApplication::translate("MainWindow", "24\347\202\271\346\270\270\346\210\217", nullptr));
        ruleBtn->setText(QCoreApplication::translate("MainWindow", "\346\270\270\346\210\217\350\247\204\345\210\231", nullptr));
        rankBtn->setText(QCoreApplication::translate("MainWindow", "\346\216\222\350\241\214\346\246\234", nullptr));
        labelUser->setText(QCoreApplication::translate("MainWindow", "\346\234\252\347\231\273\345\275\225", nullptr));
        logoutBtn->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250 24 \347\202\271\346\270\270\346\210\217", nullptr));
        loginBtn->setText(QCoreApplication::translate("MainWindow", "\347\253\213\345\215\263\347\231\273\345\275\225", nullptr));
        registerBtn->setText(QCoreApplication::translate("MainWindow", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
