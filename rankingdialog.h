#ifndef RANKINGDIALOG_H
#define RANKINGDIALOG_H

#include <QDialog>

class UserDatabase;

namespace Ui {
class RankingDialog;
}

class RankingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RankingDialog(const UserDatabase& database,QWidget *parent = nullptr);
    ~RankingDialog();

private:
    Ui::RankingDialog *ui;
    const UserDatabase&    m_userdatabase;
};

#endif // RANKINGDIALOG_H
