#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

// 前置声明，减少头文件依赖，提高编译速度
QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

/**
 * @brief 用户登录对话框
 * 负责显示登录界面、收集用户名和密码、提供 accept/reject 行为
 */
class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * @param parent 父窗口，通常传 MainWindow
     */
    explicit LoginDialog(QWidget *parent = nullptr);

    /** 析构函数 */
    ~LoginDialog() override = default;

    /** 获取用户输入的用户名（已去除首尾空格） */
    QString account() const;

    /** 获取用户输入的密码（明文） */
    QString password() const;

private:
    QLineEdit   *m_accountEdit;   // 用户名输入框
    QLineEdit   *m_passwordEdit;  // 密码输入框
    QPushButton *m_okBtn;         // 登录按钮
    QPushButton *m_cancelBtn;     // 取消按钮
};

#endif // LOGINDIALOG_H
