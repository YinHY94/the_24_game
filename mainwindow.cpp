#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "LoginDialog.h"
#include "UserDatabase.h"

#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QListWidget>
#include <QComboBox>
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
#include <QCoreApplication>
#include <QDir>

#include "LoginDialog.h"
#include "RegisterDialog.h"
#include "GameWidget.h"
#include "RuleDialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_userDb()  // 初始化用户数据库
{
    ui->setupUi(this);



    initializeUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initializeUI()
{
    ui->stackedWidget->setCurrentWidget(ui->pageWelcome);
    ui->logoutBtn->setVisible(false);
    ui->labelUser->setText("未登录");
}

/* -------------------------------------------------------------
   用户登录：显示登录对话框，验证用户身份
   ------------------------------------------------------------- */
void MainWindow::UserLogin()
{
    // 创建并显示登录对话框
    LoginDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted) {
        return;  // 用户取消登录
    }

    // 获取用户输入
    QString inputAccount = dialog.account();
    QString inputPassword = dialog.password();

    // 基本验证：输入不能为空
    if (inputAccount.isEmpty() || inputPassword.isEmpty()) {
        QMessageBox::warning(this, "登录失败", "账号和密码不能为空！");
        return;
    }

    // 验证用户身份
    const User* user = m_userDb.verifyLogin(inputAccount, inputPassword);
    if (user) {
        // 登录成功
        m_currentUser = user;
        QMessageBox::information(this, "登录成功",
                                 QString("欢迎回来，%1！当前最高得分：%2").arg(user->name).arg(user->score));

        // 更新界面状态
        ui->logoutBtn->setVisible(true);
        ui->labelUser->setText(QString("%1").arg(user->name));
        updateUIAfterLogin();

    } else {
        // 登录失败
        QMessageBox::warning(this, "登录失败", "账号或密码错误！");
    }
}

/* -------------------------------------------------------------
   用户登出：清除当前用户状态，恢复未登录界面
   ------------------------------------------------------------- */
void MainWindow::UserLogout()
{
    m_currentUser = nullptr;
    ui->logoutBtn->setVisible(false);
    initializeUI();
    ui->stackedWidget->setCurrentWidget(ui->pageWelcome);

    if(m_gameWidget!=nullptr){
        delete m_gameWidget;
    }
    QMessageBox::information(this, "登出成功", "您已退出登录");
}

/* -------------------------------------------------------------
   登录成功后更新界面：根据用户权限显示/隐藏功能
   ------------------------------------------------------------- */
void MainWindow::updateUIAfterLogin()
{
    if (m_currentUser == nullptr) {
        return;
    }
    m_gameWidget=new GameWidget(*m_currentUser,this);
    ui->stackedWidget->addWidget(m_gameWidget);
    ui->stackedWidget->setCurrentWidget(m_gameWidget);
    // 显示当前用户信息（如果有状态栏或标签）
    // ui->statusBarLabel->setText(QString("已登录：%1").arg(m_currentUser->name));

}

/* -------------------------------------------------------------
   加载用户数据库：从 JSON 文件读取用户数据
   ------------------------------------------------------------- */
void MainWindow::loadUserDatabase()
{
    // UserDatabase 类已自动处理加载
    // 如果需要手动重新加载：
    m_userDb.loadFromFile("users.json");
}

/* -------------------------------------------------------------
   验证用户登录：检查账号密码是否匹配（已由 UserDatabase 处理）
   ------------------------------------------------------------- */
bool MainWindow::verifyUserLogin(const QString& account, const QString& password)
{
    // 委托给 UserDatabase 处理
    const User* user = m_userDb.verifyLogin(account, password);
    if (user) {
        m_currentUser = user;
        return true;
    }
    return false;
}

void MainWindow::UserRegister()
{
    // 创建并显示登录对话框
    RegisterDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted) {
        return;  // 用户取消注册
    }

    // 获取用户输入
    QString inputAccount = dialog.account();
    QString inputPassword = dialog.password();
    QString inputConfirm = dialog.confirm();

    // 基本验证：输入不能为空
    if (inputAccount.isEmpty() || inputPassword.isEmpty() ) {
        QMessageBox::warning(this, "注册失败", "所有字段不能为空！");
        return;
    }
    else if (inputPassword!=inputConfirm){
        QMessageBox::warning(this, "注册失败", "两次输入的密码不一致！");
        return;
    }
    else if (inputPassword.length()<6){
        QMessageBox::warning(this, "注册失败", "密码长度不得小于六位！");
        return;
    }

    // 验证用户身份
    User user = User(inputAccount,inputPassword,0);
    if (m_userDb.addUser(user)) {
        QMessageBox::information(this, "注册成功",QString("欢迎新用户"));
    } else {
        // 注册失败
        QMessageBox::warning(this, "注册失败", "用户名已存在！");
    }
}


void MainWindow::on_ruleBtn_clicked(){
    RuleDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted) {
        return;  // 用户取消注册
    }

}


void MainWindow::on_loginBtn_clicked()
{
    UserLogin();
}


void MainWindow::on_logoutBtn_clicked()
{
    UserLogout();
}


void MainWindow::on_registerBtn_clicked()
{
    UserRegister();
}


