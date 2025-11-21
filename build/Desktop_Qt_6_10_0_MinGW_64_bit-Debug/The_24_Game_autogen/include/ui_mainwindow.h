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
    QSpacerItem *horizontalSpacer;
    QLabel *labelUser;
    QPushButton *logoutBtn;
    QStackedWidget *stackedWidget;
    QWidget *pageWelcome;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *loginBtn;
    QPushButton *registerBtn;
    QWidget *pageMain;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(972, 606);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow { background: #F8FAFC; }\n"
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
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #6366F1, stop:1 #4F46E5);\n"
"        border-bottom: 1px solid #4338CA;\n"
"       "));
        horizontalLayout_top = new QHBoxLayout(frameTop);
        horizontalLayout_top->setObjectName("horizontalLayout_top");
        horizontalLayout_top->setContentsMargins(24, 0, 24, 0);
        labelLogo = new QLabel(frameTop);
        labelLogo->setObjectName("labelLogo");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        labelLogo->setFont(font);
        labelLogo->setStyleSheet(QString::fromUtf8("color: white;"));

        horizontalLayout_top->addWidget(labelLogo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_top->addItem(horizontalSpacer);

        labelUser = new QLabel(frameTop);
        labelUser->setObjectName("labelUser");
        QFont font1;
        font1.setPointSize(11);
        labelUser->setFont(font1);
        labelUser->setStyleSheet(QString::fromUtf8("color: #C3D0FF;"));

        horizontalLayout_top->addWidget(labelUser);

        logoutBtn = new QPushButton(frameTop);
        logoutBtn->setObjectName("logoutBtn");
        logoutBtn->setMinimumSize(QSize(80, 32));
        logoutBtn->setVisible(false);
        logoutBtn->setStyleSheet(QString::fromUtf8("\n"
"           QPushButton {\n"
"               background: rgba(255,255,255,0.2);\n"
"               color: white;\n"
"               border: 1px solid rgba(255,255,255,0.3);\n"
"               border-radius: 6px;\n"
"               padding: 0px 12px;\n"
"           }\n"
"           QPushButton:hover { background: rgba(255,255,255,0.3); }\n"
"          "));

        horizontalLayout_top->addWidget(logoutBtn);


        verticalLayout_main->addWidget(frameTop);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background: transparent;"));
        pageWelcome = new QWidget();
        pageWelcome->setObjectName("pageWelcome");
        verticalLayout = new QVBoxLayout(pageWelcome);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(pageWelcome);
        label->setObjectName("label");
        QFont font2;
        font2.setPointSize(28);
        font2.setBold(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: #1E293B;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        loginBtn = new QPushButton(pageWelcome);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setMinimumSize(QSize(220, 56));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        loginBtn->setFont(font3);
        loginBtn->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"                background: #000080;\n"
"                color: white;\n"
"                border-radius: 12px;\n"
"            }\n"
"            QPushButton:hover { background: #4F46E5; }\n"
"           "));

        verticalLayout->addWidget(loginBtn);

        registerBtn = new QPushButton(pageWelcome);
        registerBtn->setObjectName("registerBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(registerBtn->sizePolicy().hasHeightForWidth());
        registerBtn->setSizePolicy(sizePolicy);
        registerBtn->setMinimumSize(QSize(0, 40));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        registerBtn->setFont(font4);
        registerBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        registerBtn->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"                color: #6366F1;\n"
"                background: transparent;\n"
"                border: none;\n"
"                padding: 8px 16px;\n"
"                border-radius: 6px;\n"
"            }\n"
"            QPushButton:hover {\n"
"                background: rgba(99, 102, 241, 0.1);\n"
"                color: #4F46E5;\n"
"            }\n"
"            QPushButton:pressed {\n"
"                background: rgba(99, 102, 241, 0.2);\n"
"            }\n"
"        "));
        registerBtn->setFlat(true);

        verticalLayout->addWidget(registerBtn);

        stackedWidget->addWidget(pageWelcome);
        pageMain = new QWidget();
        pageMain->setObjectName("pageMain");
        verticalLayout_2 = new QVBoxLayout(pageMain);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(pageMain);
        label_2->setObjectName("label_2");
        QFont font5;
        font5.setPointSize(20);
        label_2->setFont(font5);

        verticalLayout_2->addWidget(label_2);

        stackedWidget->addWidget(pageMain);

        verticalLayout_main->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "24\347\202\271\346\270\270\346\210\217\344\270\255\345\277\203", nullptr));
        labelLogo->setText(QCoreApplication::translate("MainWindow", "24\347\202\271\346\270\270\346\210\217", nullptr));
        labelUser->setText(QCoreApplication::translate("MainWindow", "\346\234\252\347\231\273\345\275\225", nullptr));
        logoutBtn->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250 24 \347\202\271\346\270\270\346\210\217", nullptr));
        loginBtn->setText(QCoreApplication::translate("MainWindow", "\347\253\213\345\215\263\347\231\273\345\275\225", nullptr));
        registerBtn->setText(QCoreApplication::translate("MainWindow", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237\347\253\213\345\215\263\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\270\273\345\212\237\350\203\275\345\214\272\357\274\210\345\267\262\347\231\273\345\275\225\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
