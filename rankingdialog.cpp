#include "rankingdialog.h"
#include "ui_rankingdialog.h"


#include "UserDatabase.h"


RankingDialog::RankingDialog(const UserDatabase& database,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RankingDialog)
    , m_userdatabase(database)
{
    ui->setupUi(this);

    // 1. 拷贝一份用户数据，避免影响原始 m_users 顺序
    QVector<User> sortedUsers = m_userdatabase.users();

    // 2. 按分数从高到低排序
    std::sort(sortedUsers.begin(), sortedUsers.end(),
              [](const User &a, const User &b) {
                  return a.score > b.score;
              });

    // 3. 只取前三名
    size_t limit = std::min<size_t>(3, static_cast<size_t>(sortedUsers.size()));

    switch (limit) {
    case 0:
        break;
    case 1:
        ui->labelRank1->setText(
            QString("NO1. %1  %2分")
                .arg(sortedUsers.at(0).name)
                .arg(sortedUsers.at(0).score));
        break;
    case 2:
        ui->labelRank1->setText(
            QString("NO1. %1  %2分")
                .arg(sortedUsers.at(0).name)
                .arg(sortedUsers.at(0).score));
        ui->labelRank2->setText(
            QString("NO2. %1  %2分")
                .arg(sortedUsers.at(1).name)
                .arg(sortedUsers.at(1).score));
        break;
    case 3:
        ui->labelRank1->setText(
            QString("NO1. %1  %2分")
                .arg(sortedUsers.at(0).name)
                .arg(sortedUsers.at(0).score));
        ui->labelRank2->setText(
            QString("NO2. %1  %2分")
                .arg(sortedUsers.at(1).name)
                .arg(sortedUsers.at(1).score));
        ui->labelRank3->setText(
            QString("NO3. %1  %2分")
                .arg(sortedUsers.at(2).name)
                .arg(sortedUsers.at(2).score));
        break;
    default:
        break;
    }
}


RankingDialog::~RankingDialog()
{
    delete ui;
}




