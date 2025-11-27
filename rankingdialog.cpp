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

    switch (limit) {
    case 0:
        break;
    case 1:
        ui->labelRank1->setText(QString("NO1. %1  %2分").arg(m_userdatabase.m_users.at(0).name).arg(m_userdatabase.m_users.at(0).score));
        break;
    case 2:
        ui->labelRank1->setText(QString("NO1. %1  %2分").arg(m_userdatabase.m_users.at(0).name).arg(m_userdatabase.m_users.at(0).score));
        ui->labelRank2->setText(QString("NO2. %1  %2分").arg(m_userdatabase.m_users.at(1).name).arg(m_userdatabase.m_users.at(1).score));
        break;
    case 3:
        ui->labelRank1->setText(QString("NO1. %1  %2分").arg(m_userdatabase.m_users.at(0).name).arg(m_userdatabase.m_users.at(0).score));
        ui->labelRank2->setText(QString("NO2. %1  %2分").arg(m_userdatabase.m_users.at(1).name).arg(m_userdatabase.m_users.at(1).score));
        ui->labelRank3->setText(QString("NO3. %1  %2分").arg(m_userdatabase.m_users.at(2).name).arg(m_userdatabase.m_users.at(2).score));
        break;
    default:
        break;
    }

}

RankingDialog::~RankingDialog()
{
    delete ui;
}




