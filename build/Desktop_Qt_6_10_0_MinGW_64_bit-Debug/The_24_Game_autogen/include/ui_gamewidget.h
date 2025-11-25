/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QVBoxLayout *mainLayout;
    QHBoxLayout *topLayout;
    QLabel *m_userLabel;
    QSpacerItem *horizontalSpacer_1;
    QLabel *m_roundLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *m_timerLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *m_scoreLabel;
    QHBoxLayout *cardsLayout;
    QLabel *m_cardLabels_0;
    QLabel *m_cardLabels_1;
    QLabel *m_cardLabels_2;
    QLabel *m_cardLabels_3;
    QHBoxLayout *exprLayout;
    QLabel *exprTipLabel;
    QLineEdit *m_exprEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *m_messageLabel;
    QHBoxLayout *btnLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *m_startBtn;
    QPushButton *m_submitBtn;
    QPushButton *m_nextBtn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName("GameWidget");
        GameWidget->resize(680, 520);
        GameWidget->setStyleSheet(QString::fromUtf8("\n"
"QWidget { background-color: #0f172a; color: #f9fafb; }\n"
"QLabel  { font-size: 16px; }\n"
"QPushButton {\n"
"    background-color: #10b981;\n"
"    color: white;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    border: none;\n"
"    font-size: 16px;\n"
"}\n"
"QPushButton:disabled { background-color: #6b7280; }\n"
"QPushButton:hover:!disabled { background-color: #059669; }\n"
"QLineEdit {\n"
"    background-color: #111827;\n"
"    border: 1px solid #374151;\n"
"    padding: 6px;\n"
"    border-radius: 4px;\n"
"    font-size: 18px;\n"
"}\n"
"   "));
        mainLayout = new QVBoxLayout(GameWidget);
        mainLayout->setSpacing(20);
        mainLayout->setContentsMargins(30, 30, 30, 30);
        mainLayout->setObjectName("mainLayout");
        topLayout = new QHBoxLayout();
        topLayout->setObjectName("topLayout");
        m_userLabel = new QLabel(GameWidget);
        m_userLabel->setObjectName("m_userLabel");
        QFont font;
        font.setBold(true);
        m_userLabel->setFont(font);

        topLayout->addWidget(m_userLabel);

        horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topLayout->addItem(horizontalSpacer_1);

        m_roundLabel = new QLabel(GameWidget);
        m_roundLabel->setObjectName("m_roundLabel");

        topLayout->addWidget(m_roundLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topLayout->addItem(horizontalSpacer_2);

        m_timerLabel = new QLabel(GameWidget);
        m_timerLabel->setObjectName("m_timerLabel");
        m_timerLabel->setFont(font);

        topLayout->addWidget(m_timerLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topLayout->addItem(horizontalSpacer_3);

        m_scoreLabel = new QLabel(GameWidget);
        m_scoreLabel->setObjectName("m_scoreLabel");
        m_scoreLabel->setFont(font);

        topLayout->addWidget(m_scoreLabel);


        mainLayout->addLayout(topLayout);

        cardsLayout = new QHBoxLayout();
        cardsLayout->setSpacing(20);
        cardsLayout->setObjectName("cardsLayout");
        m_cardLabels_0 = new QLabel(GameWidget);
        m_cardLabels_0->setObjectName("m_cardLabels_0");
        m_cardLabels_0->setMinimumSize(QSize(100, 140));
        m_cardLabels_0->setMaximumSize(QSize(100, 140));
        m_cardLabels_0->setStyleSheet(QString::fromUtf8("background-color: #1e293b; border: 3px solid #475569; border-radius: 12px;"));
        m_cardLabels_0->setScaledContents(true);
        m_cardLabels_0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        cardsLayout->addWidget(m_cardLabels_0);

        m_cardLabels_1 = new QLabel(GameWidget);
        m_cardLabels_1->setObjectName("m_cardLabels_1");
        m_cardLabels_1->setMinimumSize(QSize(100, 140));
        m_cardLabels_1->setMaximumSize(QSize(100, 140));
        m_cardLabels_1->setStyleSheet(QString::fromUtf8("background-color: #1e293b; border: 3px solid #475569; border-radius: 12px;"));
        m_cardLabels_1->setScaledContents(true);
        m_cardLabels_1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        cardsLayout->addWidget(m_cardLabels_1);

        m_cardLabels_2 = new QLabel(GameWidget);
        m_cardLabels_2->setObjectName("m_cardLabels_2");
        m_cardLabels_2->setMinimumSize(QSize(100, 140));
        m_cardLabels_2->setMaximumSize(QSize(100, 140));
        m_cardLabels_2->setStyleSheet(QString::fromUtf8("background-color: #1e293b; border: 3px solid #475569; border-radius: 12px;"));
        m_cardLabels_2->setScaledContents(true);
        m_cardLabels_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        cardsLayout->addWidget(m_cardLabels_2);

        m_cardLabels_3 = new QLabel(GameWidget);
        m_cardLabels_3->setObjectName("m_cardLabels_3");
        m_cardLabels_3->setMinimumSize(QSize(100, 140));
        m_cardLabels_3->setMaximumSize(QSize(100, 140));
        m_cardLabels_3->setStyleSheet(QString::fromUtf8("background-color: #1e293b; border: 3px solid #475569; border-radius: 12px;"));
        m_cardLabels_3->setScaledContents(true);
        m_cardLabels_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        cardsLayout->addWidget(m_cardLabels_3);


        mainLayout->addLayout(cardsLayout);

        exprLayout = new QHBoxLayout();
        exprLayout->setObjectName("exprLayout");
        exprTipLabel = new QLabel(GameWidget);
        exprTipLabel->setObjectName("exprTipLabel");
        exprTipLabel->setFont(font);

        exprLayout->addWidget(exprTipLabel);

        m_exprEdit = new QLineEdit(GameWidget);
        m_exprEdit->setObjectName("m_exprEdit");

        exprLayout->addWidget(m_exprEdit);


        mainLayout->addLayout(exprLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        m_messageLabel = new QLabel(GameWidget);
        m_messageLabel->setObjectName("m_messageLabel");

        horizontalLayout->addWidget(m_messageLabel);


        mainLayout->addLayout(horizontalLayout);

        btnLayout = new QHBoxLayout();
        btnLayout->setObjectName("btnLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        btnLayout->addItem(horizontalSpacer_4);

        m_startBtn = new QPushButton(GameWidget);
        m_startBtn->setObjectName("m_startBtn");
        m_startBtn->setMinimumSize(QSize(120, 40));

        btnLayout->addWidget(m_startBtn);

        m_submitBtn = new QPushButton(GameWidget);
        m_submitBtn->setObjectName("m_submitBtn");
        m_submitBtn->setMinimumSize(QSize(120, 40));

        btnLayout->addWidget(m_submitBtn);

        m_nextBtn = new QPushButton(GameWidget);
        m_nextBtn->setObjectName("m_nextBtn");
        m_nextBtn->setEnabled(false);
        m_nextBtn->setMinimumSize(QSize(120, 40));

        btnLayout->addWidget(m_nextBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        btnLayout->addItem(horizontalSpacer_5);


        mainLayout->addLayout(btnLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        mainLayout->addItem(verticalSpacer);


        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QCoreApplication::translate("GameWidget", "24\347\202\271\346\270\270\346\210\217", nullptr));
        m_userLabel->setText(QCoreApplication::translate("GameWidget", "\347\216\251\345\256\266\357\274\232\346\234\252\347\237\245", nullptr));
        m_roundLabel->setText(QCoreApplication::translate("GameWidget", "\347\254\254 1 \345\261\200", nullptr));
        m_timerLabel->setText(QCoreApplication::translate("GameWidget", "00:--", nullptr));
        m_scoreLabel->setText(QCoreApplication::translate("GameWidget", "\346\200\273\345\210\206\357\274\2320", nullptr));
        m_cardLabels_0->setText(QString());
        m_cardLabels_1->setText(QString());
        m_cardLabels_2->setText(QString());
        m_cardLabels_3->setText(QString());
        exprTipLabel->setText(QCoreApplication::translate("GameWidget", "\350\257\267\350\276\223\345\205\245\350\256\241\347\256\227\350\241\250\350\276\276\345\274\217\357\274\210\346\210\226\350\276\223\345\205\245 NO \346\224\276\345\274\203\357\274\211\357\274\232", nullptr));
        m_exprEdit->setPlaceholderText(QCoreApplication::translate("GameWidget", "\344\276\213\345\246\202\357\274\232(3+5)*2+4", nullptr));
        m_messageLabel->setText(QCoreApplication::translate("GameWidget", "TextLabel", nullptr));
        m_startBtn->setText(QCoreApplication::translate("GameWidget", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        m_submitBtn->setText(QCoreApplication::translate("GameWidget", "\346\217\220\344\272\244\347\255\224\346\241\210", nullptr));
        m_nextBtn->setText(QCoreApplication::translate("GameWidget", "\344\270\213\344\270\200\345\261\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
