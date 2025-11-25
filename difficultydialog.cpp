#include "difficultydialog.h"
#include "ui_difficultydialog.h"

DifficultyDialog::DifficultyDialog(Difficulty &difficulty, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DifficultyDialog)
    , m_difficulty(difficulty)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
}

DifficultyDialog::~DifficultyDialog()
{
    delete ui;
}

void DifficultyDialog::on_easyBtn_clicked(){
    m_difficulty=Easy;
    accept();
}


void DifficultyDialog::on_normalBtn_clicked(){
    m_difficulty=Normal;
    accept();
}

void DifficultyDialog::on_hardBtn_clicked(){
    m_difficulty=Hard;
    accept();
}
