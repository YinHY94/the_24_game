/********************************************************************************
** Form generated from reading UI file 'rankingdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKINGDIALOG_H
#define UI_RANKINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RankingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topBar;
    QPushButton *closeButton;
    QLabel *labelTitle;
    QSpacerItem *spacer;
    QSpacerItem *topSpacer;
    QLabel *labelRank1;
    QLabel *labelRank2;
    QLabel *labelRank3;
    QSpacerItem *bottomSpacer;

    void setupUi(QDialog *RankingDialog)
    {
        if (RankingDialog->objectName().isEmpty())
            RankingDialog->setObjectName("RankingDialog");
        RankingDialog->resize(300, 400);
        RankingDialog->setStyleSheet(QString::fromUtf8("QDialog { background-color: #0f172a; border-radius: 20px; }\n"
"\n"
"#labelTitle { color: white; font-size: 28px; font-weight: bold; }\n"
"\n"
"#labelRank1, #labelRank2, #labelRank3 {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 18px;\n"
"    border-radius: 16px;\n"
"    padding: 12px 24px;\n"
"    min-height: 48px;\n"
"    max-width: 260px;\n"
"}\n"
"\n"
"#labelRank1 { background-color: #4338CA; }\n"
"#labelRank2 { background-color: #6366F1; }\n"
"#labelRank3 { background-color: #C3D0FF; }\n"
"\n"
"#closeButton {\n"
"    background: transparent;\n"
"    color: #94a3b8;\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"#closeButton:hover { color: #ef4444; }"));
        RankingDialog->setModal(true);
        verticalLayout = new QVBoxLayout(RankingDialog);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 6, -1, 20);
        topBar = new QHBoxLayout();
        topBar->setSpacing(20);
#ifndef Q_OS_MAC
        topBar->setContentsMargins(0, 0, 0, 0);
#endif
        topBar->setObjectName("topBar");

        verticalLayout->addLayout(topBar);

        closeButton = new QPushButton(RankingDialog);
        closeButton->setObjectName("closeButton");
        closeButton->setEnabled(true);
        closeButton->setMaximumSize(QSize(30, 30));
        closeButton->setFlat(true);

        verticalLayout->addWidget(closeButton, 0, Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop);

        labelTitle = new QLabel(RankingDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        spacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(spacer);

        topSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(topSpacer);

        labelRank1 = new QLabel(RankingDialog);
        labelRank1->setObjectName("labelRank1");
        labelRank1->setMinimumSize(QSize(240, 72));
        labelRank1->setMaximumSize(QSize(308, 52));
        labelRank1->setBaseSize(QSize(0, 5));
        labelRank1->setStyleSheet(QString::fromUtf8("QDialog { background-color: #0f172a; border-radius: 20px; }\n"
"\n"
"#labelTitle { color: white; font-size: 28px; font-weight: bold; }\n"
"\n"
"#labelRank1, #labelRank2, #labelRank3 {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 18px;\n"
"    border-radius: 16px;\n"
"    padding: 12px 24px;\n"
"    min-height: 48px;\n"
"    max-width: 260px;\n"
"}\n"
"\n"
"#labelRank1 { background-color: #4338CA; }\n"
"#labelRank2 { background-color: #6366F1; }\n"
"#labelRank3 { background-color: #C3D0FF; }\n"
"\n"
"#closeButton {\n"
"    background: transparent;\n"
"    color: #94a3b8;\n"
"    font-size: 26px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"#closeButton:hover { color: #ef4444; }"));
        labelRank1->setScaledContents(false);
        labelRank1->setMargin(0);
        labelRank1->setIndent(-1);

        verticalLayout->addWidget(labelRank1, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        labelRank2 = new QLabel(RankingDialog);
        labelRank2->setObjectName("labelRank2");
        labelRank2->setMinimumSize(QSize(240, 72));
        labelRank2->setMaximumSize(QSize(308, 52));

        verticalLayout->addWidget(labelRank2, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        labelRank3 = new QLabel(RankingDialog);
        labelRank3->setObjectName("labelRank3");
        labelRank3->setMinimumSize(QSize(240, 72));
        labelRank3->setMaximumSize(QSize(308, 52));

        verticalLayout->addWidget(labelRank3, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(bottomSpacer);


        retranslateUi(RankingDialog);
        QObject::connect(closeButton, &QPushButton::clicked, RankingDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RankingDialog);
    } // setupUi

    void retranslateUi(QDialog *RankingDialog)
    {
        RankingDialog->setWindowTitle(QCoreApplication::translate("RankingDialog", "\346\216\222\350\241\214\346\246\234", nullptr));
        closeButton->setText(QCoreApplication::translate("RankingDialog", "\303\227", nullptr));
        labelTitle->setText(QCoreApplication::translate("RankingDialog", "\346\216\222\350\241\214\346\246\234", nullptr));
        labelRank1->setText(QCoreApplication::translate("RankingDialog", "1. \350\266\205\347\272\247\346\227\240\346\225\214\351\225\277\345\220\215\345\255\227\347\216\251\345\256\266    999999 \345\210\206", nullptr));
        labelRank2->setText(QCoreApplication::translate("RankingDialog", "2. \346\210\221\345\220\215\345\255\227\344\271\237\345\276\210\351\225\277\345\223\210\345\223\210\345\223\210\345\223\210    88888 \345\210\206", nullptr));
        labelRank3->setText(QCoreApplication::translate("RankingDialog", "3. \347\237\255\345\220\215\345\255\227    77777 \345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankingDialog: public Ui_RankingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKINGDIALOG_H
