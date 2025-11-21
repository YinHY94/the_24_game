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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_userDb()  // 初始化用户数据库
{
    ui->setupUi(this);

    initializeUI();
}

/* -------------------------------------------------------------
   析构函数：清理资源
   ------------------------------------------------------------- */
MainWindow::~MainWindow()
{
    delete ui;
}

/* -------------------------------------------------------------
   初始化界面：设置未登录状态下的控件可见性
   ------------------------------------------------------------- */
void MainWindow::initializeUI()
{
    // 登录前隐藏相关控件
    ui->logoutBtn->setVisible(false);
    // updateBtnState(false);  // 如果有状态更新函数

    // 设置其他控件初始状态
    // ui->searchLineEdit->setEnabled(false);
    // ui->searchButton->setEnabled(false);
    // ... 其他初始化
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
                                 QString("欢迎回来，%1！当前积分：%2").arg(user->name).arg(user->score));

        // 更新界面状态
        ui->logoutBtn->setVisible(true);
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

    QMessageBox::information(this, "登出成功", "您已安全登出");
}

/* -------------------------------------------------------------
   登录成功后更新界面：根据用户权限显示/隐藏功能
   ------------------------------------------------------------- */
void MainWindow::updateUIAfterLogin()
{
    if (!m_currentUser) {
        return;
    }

    // 显示当前用户信息（如果有状态栏或标签）
    // ui->statusBarLabel->setText(QString("已登录：%1").arg(m_currentUser->name));

    // 启用搜索功能
    // ui->searchLineEdit->setEnabled(true);
    // ui->searchButton->setEnabled(true);

    // 根据用户权限调整功能可见性
    // if (m_currentUser->isAdmin) {
    //     ui->adminPanel->setVisible(true);
    // }
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

/* -------------------------------------------------------------
   自动连接的槽函数（Qt Designer 自动连接）
   ------------------------------------------------------------- */

/**
 * 登录按钮点击槽函数
 * 自动连接：on_loginButton_clicked()
 */
void MainWindow::on_loginBtn_clicked()
{
    UserLogin();
}

/**
 * 登出按钮点击槽函数
 * 自动连接：on_logoutButton_clicked()
 */
void MainWindow::on_logoutBtn_clicked()
{
    UserLogout();
}

/**
 * 用户注册按钮点击槽函数（如果有注册功能）
 * 自动连接：on_registerButton_clicked()
 */
void MainWindow::on_registerBtn_clicked()
{
    // 显示注册对话框（待实现）
    // UserRegister();
}


