#ifndef DIFFICULTYDIALOG_H
#define DIFFICULTYDIALOG_H

#include <QDialog>
#include "gamewidget.h"

namespace Ui {
class DifficultyDialog;
}

class DifficultyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DifficultyDialog(Difficulty& difficulty,QWidget *parent = nullptr);
    ~DifficultyDialog();

private slots:
    void on_easyBtn_clicked();
    void on_normalBtn_clicked();
    void on_hardBtn_clicked();

private:
    Ui::DifficultyDialog *ui;
    Difficulty& m_difficulty;
};

#endif // DIFFICULTYDIALOG_H
