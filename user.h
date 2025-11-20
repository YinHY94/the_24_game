#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    QString name;
    QString password;
    int score = 0;

    // 构造函数
    User() = default;
    User(const QString& n, const QString& p = "", int s = 0)
        : name(n), password(p), score(s) {}

    // 验证账号密码
    bool verifyAccount(const QString& inputName, const QString& inputPwd) const {
        return name == inputName && password == inputPwd;
    }

    QString toString() const {
        return QString("User{name='%1', score=%2}").arg(name).arg(score);
    }
};


#endif // USER_H
