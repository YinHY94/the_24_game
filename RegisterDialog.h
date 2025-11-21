#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

// 前置声明，减少头文件依赖，提高编译速度
QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE


class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog() override = default;

    /** 获取用户输入的用户名（已去除首尾空格） */
    QString account() const;

    /** 获取用户输入的密码 */
    QString password() const;

    /** 获取用户输入的确认密码 */
    QString confirm() const;

private:
    QLineEdit   *m_accountEdit;   // 用户名输入框
    QLineEdit   *m_passwordEdit;  // 密码输入框
    QLineEdit   *m_confirmEdit;   // 密码确认框

    QPushButton *m_okBtn;         // 注册按钮
    QPushButton *m_cancelBtn;     // 取消按钮
};



#endif // REGISTERDIALOG_H
