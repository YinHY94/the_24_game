#include "rankingdialog.h"
#include "ui_rankingdialog.h"


#include "UserDatabase.h"


RankingDialog::RankingDialog(const UserDatabase& database,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RankingDialog)
    , m_userdatabase(database)
{
    ui->setupUi(this);

    size_t limit = std::min<size_t>(3, m_userdatabase.m_users.size());

    for (size_t i = 0; i < limit; ++i) {
        ui->labelRank1->setText(QString("NO%1. %2  %3分").arg(i).arg(m_userdatabase.m_users.at(0).name).arg(m_userdatabase.m_users.at(0).score));
    }

}

RankingDialog::~RankingDialog()
{
    delete ui;
}




