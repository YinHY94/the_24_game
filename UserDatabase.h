#ifndef USERDATABASE_H
#define USERDATABASE_H

#include "User.h"
#include <QVector>
#include <QString>

class UserDatabase
{
public:
    UserDatabase();

    // 加载用户数据（从 JSON 文件）
    bool loadFromFile(const QString& filename);

    // 保存用户数据
    bool saveToFile(const QString& filename) const;

    // 验证登录
    const User* verifyLogin(const QString& name, const QString& password) const;

    // 添加新用户（注册）
    bool addUser(const User& user);

    bool updateUserScore(const User& user);

    // 获取所有用户（排行榜用）
    const QVector<User>& users() const { return m_users; }

private:
    QVector<User> m_users;
    QString m_filename;
};


#endif // USERDATABASE_H
