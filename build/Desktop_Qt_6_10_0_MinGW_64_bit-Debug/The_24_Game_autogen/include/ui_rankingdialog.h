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
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RankingDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *labelTitle;
    QSpacerItem *topSpacer;
    QLabel *labelRank1;
    QLabel *labelRank2;
    QLabel *labelRank3;
    QSpacerItem *bottomSpacer;

    void setupUi(QDialog *RankingDialog)
    {
        if (RankingDialog->objectName().isEmpty())
            RankingDialog->setObjectName("RankingDialog");
        RankingDialog->resize(378, 440);
        RankingDialog->setStyleSheet(QString::fromUtf8("\n"
"QDialog { background-color: #0f172a; border-radius: 20px; }\n"
"\n"
"#labelTitle { color: white; font-size: 28px; font-weight: bold; }\n"
"\n"
"#closeButton {\n"
"    background: transparent;\n"
"    color: #94a3b8;\n"
"    font-size: 28px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"#closeButton:hover { color: #ef4444; }\n"
"\n"
"#labelRank1, #labelRank2, #labelRank3 {\n"
"    color: black;\n"
"    font-weight: bold;\n"
"    font-size: 16px;  \n"
"    border-radius: 16px;\n"
"    padding: 14px 20px;\n"
"    background-color: #4338CA;\n"
"}\n"
"#labelRank1 { background-color: #009fd4; }\n"
"#labelRank2 { background-color: #00BCD4; }\n"
"#labelRank3 { background-color: #B2EBF2; }\n"
"   "));
        RankingDialog->setModal(true);
        verticalLayout = new QVBoxLayout(RankingDialog);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        labelTitle = new QLabel(RankingDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        topSpacer = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(topSpacer);

        labelRank1 = new QLabel(RankingDialog);
        labelRank1->setObjectName("labelRank1");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelRank1->sizePolicy().hasHeightForWidth());
        labelRank1->setSizePolicy(sizePolicy);
        labelRank1->setMinimumSize(QSize(295, 65));
        labelRank1->setMaximumSize(QSize(295, 65));
        labelRank1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelRank1->setWordWrap(true);

        verticalLayout->addWidget(labelRank1, 0, Qt::AlignmentFlag::AlignHCenter);

        labelRank2 = new QLabel(RankingDialog);
        labelRank2->setObjectName("labelRank2");
        sizePolicy.setHeightForWidth(labelRank2->sizePolicy().hasHeightForWidth());
        labelRank2->setSizePolicy(sizePolicy);
        labelRank2->setMinimumSize(QSize(295, 65));
        labelRank2->setMaximumSize(QSize(295, 65));
        labelRank2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelRank2->setWordWrap(true);

        verticalLayout->addWidget(labelRank2, 0, Qt::AlignmentFlag::AlignHCenter);

        labelRank3 = new QLabel(RankingDialog);
        labelRank3->setObjectName("labelRank3");
        sizePolicy.setHeightForWidth(labelRank3->sizePolicy().hasHeightForWidth());
        labelRank3->setSizePolicy(sizePolicy);
        labelRank3->setMinimumSize(QSize(295, 65));
        labelRank3->setMaximumSize(QSize(295, 65));
        labelRank3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelRank3->setWordWrap(true);
        labelRank3->setIndent(-1);

        verticalLayout->addWidget(labelRank3, 0, Qt::AlignmentFlag::AlignHCenter);

        bottomSpacer = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(bottomSpacer);


        retranslateUi(RankingDialog);

        QMetaObject::connectSlotsByName(RankingDialog);
    } // setupUi

    void retranslateUi(QDialog *RankingDialog)
    {
        RankingDialog->setWindowTitle(QCoreApplication::translate("RankingDialog", "\346\216\222\350\241\214\346\246\234", nullptr));
        labelTitle->setText(QCoreApplication::translate("RankingDialog", "\346\216\222\350\241\214\346\246\234", nullptr));
        labelRank1->setText(QCoreApplication::translate("RankingDialog", "1. \350\266\205\347\272\247\346\227\240\346\225\214\351\225\277\345\220\215\345\255\227\347\216\251\345\256\266\347\234\237\347\232\204\345\276\210\351\225\277\345\276\210\351\225\277\345\276\210\351\225\277    999999 \345\210\206", nullptr));
        labelRank2->setText(QCoreApplication::translate("RankingDialog", "2. \346\210\221\345\220\215\345\255\227\344\271\237\345\276\210\351\225\277\345\223\210\345\223\210\345\223\210\345\223\210\345\223\210\345\223\210\345\223\210\345\223\210\345\223\210    888888 \345\210\206", nullptr));
        labelRank3->setText(QCoreApplication::translate("RankingDialog", "3. \347\237\255\345\220\215\345\255\227\347\216\251\345\256\266    777777 \345\210\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankingDialog: public Ui_RankingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKINGDIALOG_H
