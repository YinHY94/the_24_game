#include "LoginDialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>

/* -------------------------------------------------------------
   构造函数：完成整个登录窗口的界面搭建、样式设置和信号槽连接
   ------------------------------------------------------------- */
LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , m_accountEdit(new QLineEdit(this))
    , m_passwordEdit(new QLineEdit(this))
    , m_okBtn(new QPushButton("登录", this))
    , m_cancelBtn(new QPushButton("取消", this))
{
    // 窗口基本属性
    setWindowTitle("用户登录");
    setFixedSize(350, 200);                     // 固定大小，防止用户拉伸

    // 标题
    auto *titleLabel = new QLabel("用户登录", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "font-size: 20px; font-weight: bold; margin-bottom: 15px;");

    // 输入框设置
    m_accountEdit->setPlaceholderText("请输入用户名");
    m_accountEdit->setMinimumHeight(35);
    m_accountEdit->setMaxLength(20);
    m_passwordEdit->setEchoMode(QLineEdit::Password);   // 密码隐藏显示
    m_passwordEdit->setPlaceholderText("请输入密码");
    m_passwordEdit->setMinimumHeight(35);
    m_passwordEdit->setMaxLength(20);
    // 登录按钮样式（绿色）
    m_okBtn->setStyleSheet(
        "QPushButton {"
        "    padding: 8px 16px;"
        "    background: #10B981;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 4px;"
        "}"
        "QPushButton:hover { background: #059669; }");

    // 取消按钮样式（灰色）
    m_cancelBtn->setStyleSheet(
        "QPushButton {"
        "    padding: 8px 16px;"
        "    background: #6B7280;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 4px;"
        "}"
        "QPushButton:hover { background: #4B5563; }");

    // 表单布局：用户名 + 密码
    auto *formLayout = new QFormLayout;
    formLayout->addRow("用户名:", m_accountEdit);
    formLayout->addRow("密码:",   m_passwordEdit);

    // 按钮布局：取消在左，登录在右
    auto *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(m_cancelBtn);
    buttonLayout->addWidget(m_okBtn);

    // 主布局：标题 → 表单 → 按钮
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    // 信号槽连接（点击按钮或回车均可确认登录）
    connect(m_okBtn,     &QPushButton::clicked, this, &QDialog::accept);
    connect(m_cancelBtn, &QPushButton::clicked, this, &QDialog::reject);
    connect(m_accountEdit,  &QLineEdit::returnPressed, [=](){m_passwordEdit->setFocus();});
    connect(m_passwordEdit, &QLineEdit::returnPressed, this, &QDialog::accept);

    m_accountEdit->setFocus();


}

/* -------------------------------------------------------------
   返回用户输入的用户名，已自动去除首尾空格
   ------------------------------------------------------------- */
QString LoginDialog::account() const
{
    return m_accountEdit->text().trimmed();
}

/* -------------------------------------------------------------
   返回用户输入的密码（明文）
   ------------------------------------------------------------- */
QString LoginDialog::password() const
{
    return m_passwordEdit->text();
}
