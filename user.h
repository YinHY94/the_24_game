#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>

class User
{
public:
    QString name;
    QString password;
    QString role;
    int totalUseSeconds = 0; // 累计使用时长（秒）
    int sessionCount    = 0; // 登录次数
    std::array<int, 3> click_time = {0, 0, 0};
    int score = 0;

    User() = default;
    User(const QString& n,
         const QString& p = "",
         int s = 0,
         int totalSec = 0,
         int sessions = 0)
        : name(n)
        , password(p)
        , score(s)
        , totalUseSeconds(totalSec)
        , sessionCount(sessions)
        , role(QString("user"))
        , click_time({0,0,0})
    {}

    // 验证账号密码
    bool verifyAccount(const QString& inputName, const QString& inputPwd) const {
        return name == inputName && password == inputPwd;
    }

    bool isAdmin() const {
        return role == "admin";
    }


    // QString toString() const {
    //     return QString("User{name='%1', score=%2}").arg(name).arg(score);
    // }
};


#endif // USER_H
