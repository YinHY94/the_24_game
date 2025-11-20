#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QStackedWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QListWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include <QMenu>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileDialog>
#include <QFile>
#include <QDialog>
#include <QTimeEdit>
#include <QDialogButtonBox>
#include <QScrollArea>
#include <QIntValidator>
#include <QPixmap>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadUserDatabase()
{
    userDatabase.clear();

    // 检查用户数据文件是否存在
    if (QFile::exists(USER_FILE)) {
        QFile file(USER_FILE);
        if (!file.open(QIODevice::ReadOnly)) {
            return;
        }

        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        file.close();

        if (!doc.isArray()) {
            return;
        }



        QJsonArray root = doc.array();
        for (const auto v : std::as_const(root)) {
            QJsonObject obj = v.toObject();
            User user;
            user.name = obj["name"].toString();
            user.password = obj["password"].toString();

            if (!user.name.isEmpty()) {
                userDatabase.append(user);
            }
        }
    }
}


bool MainWindow::verifyUserLogin(const QString& account, const QString& password)
{
    for (const auto& user : userDatabase) {
        if (user.verifyAccount(account, password)) {
            currentUser = &user;
            return true;
        }
    }
    return false;
}


void MainWindow::UserLogin() {
    // 创建用户登录对话框
    QDialog loginDialog(this);
    loginDialog.setWindowTitle("用户登录");
    loginDialog.setFixedSize(350, 200);

    QVBoxLayout layout(&loginDialog);

    auto titleLabel = new QLabel("用户登录",&loginDialog);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold; margin-bottom: 15px;");

    auto accountLabel = new QLabel("用户名:",&loginDialog);
    auto accountEdit = new QLineEdit(&loginDialog);
    accountEdit->setPlaceholderText("请输入用户名");

    auto passwordLabel = new QLabel("密码:",&loginDialog);
    auto passwordEdit = new QLineEdit(&loginDialog);
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setPlaceholderText("请输入密码");

    auto okBtn = new QPushButton("登录",&loginDialog);
    auto cancelBtn = new QPushButton("取消",&loginDialog);


    connect(accountEdit, &QLineEdit::returnPressed, &loginDialog, &QDialog::accept);
    connect(passwordEdit, &QLineEdit::returnPressed, &loginDialog, &QDialog::accept);

    QHBoxLayout* buttonLayout = new QHBoxLayout(&loginDialog);
    buttonLayout->addWidget(cancelBtn);
    buttonLayout->addWidget(okBtn);

    // 表单布局
    QFormLayout* formLayout = new QFormLayout(&loginDialog);
    formLayout->addRow(accountLabel, accountEdit);
    formLayout->addRow(passwordLabel, passwordEdit);

    layout.addWidget(titleLabel);
    layout.addLayout(formLayout);
    layout.addLayout(buttonLayout);

    // 设置按钮样式
    okBtn->setStyleSheet("QPushButton { padding: 8px 16px; background: #10B981; color: white; border: none; border-radius: 4px; } QPushButton:hover { background: #059669; }");
    cancelBtn->setStyleSheet("QPushButton { padding: 8px 16px; background: #6B7280; color: white; border: none; border-radius: 4px; } QPushButton:hover { background: #4B5563; }");

    // // 连接信号
    // connect(okBtn, SIGNAL(clicked()), &loginDialog, SLOT(accept()));
    // connect(cancelBtn, SIGNAL(clicked()), &loginDialog, SLOT(reject()));

    // 显示对话框
    accountEdit->setFocus();
    if (loginDialog.exec() != QDialog::Accepted) {
        return; // 用户取消登录
    }

    QString inputAccount = accountEdit->text().trimmed();
    QString inputPassword = passwordEdit->text();


    if (inputAccount.isEmpty() || inputPassword.isEmpty()) {
        QMessageBox::warning(this, "登录失败", "账号和密码不能为空！");
        //return;
    }

    else if (verifyUserLogin(inputAccount, inputPassword)) {
        //stackedWidget->setCurrentWidget(searchPage);

        QMessageBox::information(this, "登录成功", QString("欢迎，%1！").arg(currentUser->name));

        logoutBtn->setVisible(true);
        //updateBtnState(true);

    } else {
        QMessageBox::warning(this, "登录失败", "账号或密码错误！");
    }
}


