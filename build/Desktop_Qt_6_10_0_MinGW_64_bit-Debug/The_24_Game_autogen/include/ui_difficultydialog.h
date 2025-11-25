/********************************************************************************
** Form generated from reading UI file 'difficultydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTYDIALOG_H
#define UI_DIFFICULTYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DifficultyDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QSpacerItem *topSpacer;
    QPushButton *easyBtn;
    QPushButton *normalBtn;
    QPushButton *hardBtn;
    QSpacerItem *bottomSpacer;

    void setupUi(QDialog *DifficultyDialog)
    {
        if (DifficultyDialog->objectName().isEmpty())
            DifficultyDialog->setObjectName("DifficultyDialog");
        DifficultyDialog->resize(300, 400);
        DifficultyDialog->setStyleSheet(QString::fromUtf8("\n"
"/* *************** \347\247\221\346\212\200\346\267\261\350\211\262\344\270\273\351\242\230\345\214\271\351\205\215 *************** */\n"
"QDialog {\n"
"    background-color: #1E1E1E; /* \344\270\273\347\225\214\351\235\242\346\267\261\350\211\262\350\203\214\346\231\257 */\n"
"    border-radius: 16px;\n"
"}\n"
"\n"
"/* \346\240\207\351\242\230 - \347\272\257\347\231\275\345\244\247\345\255\227 */\n"
"#labelTitle {\n"
"    color: #F0F0F0; /* \346\265\205\350\211\262\346\226\207\345\255\227 */\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \347\273\237\344\270\200\346\214\211\351\222\256\346\240\267\345\274\217\357\274\232\351\253\230\345\272\246\345\233\272\345\256\232\357\274\214\345\256\275\345\272\246100%\345\241\253\345\205\205\357\274\214\345\255\227\344\275\223\350\207\252\345\212\250\351\200\202\351\205\215 */\n"
"QPushButton {\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    min-height: 60px;\n"
"    margin-left: "
                        "15px;\n"
"    margin-right: 15px;\n"
"}\n"
"\n"
"/* \351\232\276\345\272\246\346\214\211\351\222\256\346\240\267\345\274\217\357\274\232\351\242\234\350\211\262\344\273\216\347\256\200\345\215\225\345\210\260\345\233\260\351\232\276\344\276\235\346\254\241\345\212\240\346\267\261/\345\212\240\345\274\272 */\n"
"\n"
"#easyBtn { \n"
"    background-color: #B2EBF2; /* \346\265\205\351\235\222\350\211\262 - \346\234\200\344\272\256 */\n"
"    color: #1E1E1E; /* \346\267\261\350\211\262\346\226\207\345\255\227 */\n"
"}\n"
"#easyBtn:hover {\n"
"    background-color: #80DEEA; /* \346\202\254\345\201\234\346\227\266\347\250\215\345\276\256\345\217\230\346\232\227 */\n"
"}\n"
"\n"
"#normalBtn { \n"
"    background-color: #00BCD4; /* \344\270\273\345\274\272\350\260\203\351\235\222\350\211\262 - \344\270\255\347\255\211\344\272\256\345\272\246 */\n"
"    color: #1E1E1E; /* \346\267\261\350\211\262\346\226\207\345\255\227 */\n"
"}\n"
"#normalBtn:hover {\n"
"    background-color: #00E5FF; /* \346\202\254\345\201\234\346\227"
                        "\266\346\217\220\344\272\256 */\n"
"}\n"
"\n"
"#hardBtn { \n"
"    background-color: #009fd4; /* \346\226\260\346\214\207\345\256\232\347\232\204\346\267\261\351\235\222\350\211\262 */\n"
"\n"
"    color: #1E1E1E; /* \345\255\227\344\275\223\346\224\271\344\270\272\351\273\221\350\211\262 */\n"
"}\n"
"#hardBtn:hover {\n"
"    background-color: #00BCD4; /* \346\202\254\345\201\234\346\227\266\344\275\277\347\224\250\344\270\273\345\274\272\350\260\203\350\211\262\346\217\220\344\272\256 */\n"
"    border: none; \n"
"    color: #1E1E1E; /* \344\277\235\346\214\201\351\273\221\350\211\262\346\226\207\345\255\227 */\n"
"}\n"
"   "));
        DifficultyDialog->setModal(true);
        verticalLayout = new QVBoxLayout(DifficultyDialog);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(25, 25, 25, 25);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(DifficultyDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        topSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(topSpacer);

        easyBtn = new QPushButton(DifficultyDialog);
        easyBtn->setObjectName("easyBtn");

        verticalLayout->addWidget(easyBtn);

        normalBtn = new QPushButton(DifficultyDialog);
        normalBtn->setObjectName("normalBtn");

        verticalLayout->addWidget(normalBtn);

        hardBtn = new QPushButton(DifficultyDialog);
        hardBtn->setObjectName("hardBtn");

        verticalLayout->addWidget(hardBtn);

        bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(bottomSpacer);


        retranslateUi(DifficultyDialog);

        QMetaObject::connectSlotsByName(DifficultyDialog);
    } // setupUi

    void retranslateUi(QDialog *DifficultyDialog)
    {
        DifficultyDialog->setWindowTitle(QCoreApplication::translate("DifficultyDialog", "\351\200\211\346\213\251\351\232\276\345\272\246", nullptr));
        labelTitle->setText(QCoreApplication::translate("DifficultyDialog", "\351\200\211\346\213\251\346\270\270\346\210\217\351\232\276\345\272\246", nullptr));
        easyBtn->setText(QCoreApplication::translate("DifficultyDialog", "\347\256\200\345\215\225\346\250\241\345\274\217", nullptr));
        normalBtn->setText(QCoreApplication::translate("DifficultyDialog", "\346\255\243\345\270\270\346\250\241\345\274\217", nullptr));
        hardBtn->setText(QCoreApplication::translate("DifficultyDialog", "\345\233\260\351\232\276\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DifficultyDialog: public Ui_DifficultyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTYDIALOG_H
