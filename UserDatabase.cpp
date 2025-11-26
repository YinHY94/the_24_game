#include "UserDatabase.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include <algorithm>


UserDatabase::UserDatabase()
{
    m_filename = "users.json";
    loadFromFile(m_filename);
}

bool UserDatabase::loadFromFile(const QString& filename)
{
    m_filename = filename;
    m_users.clear();

    QFile file(filename);
    if (!file.exists()) {
        return true;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "无法打开用户文件:" << filename;
        return false;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    if (!doc.isArray()) {
        qWarning() << "用户文件格式错误";
        return false;
    }

    for (const auto& v : doc.array()) {
        QJsonObject obj = v.toObject();
        User user;
        user.name = obj["name"].toString();
        user.password = obj["password"].toString();
        user.score = obj["score"].toInt();
        user.role = obj["role"].toString();
        user.sessionCount    = obj["sessionCount"].toInt();
        user.totalUseSeconds = obj ["totalseconds"].toInt();
        user.click_time[0] = obj ["easy"].toInt();
        user.click_time[1] = obj ["normal"].toInt();
        user.click_time[2] = obj ["hard"].toInt();
        if (!user.name.isEmpty()) {
            m_users.append(user);
        }
    }
    return true;
}

bool UserDatabase::saveToFile(const QString& filename) const
{
    QJsonArray array;
    for (const User& user : m_users) {
        QJsonObject obj;
        obj["name"] = user.name;
        obj["password"] = user.password;
        obj["score"] = user.score;
        obj["role"] = user.role;
        obj["totalUseSeconds"] = user.totalUseSeconds;
        obj["sessionCount"]    = user.sessionCount;
        obj["easy"] = user.click_time[0];
        obj["normal"] = user.click_time[1];
        obj["hard"] = user.click_time[2];
        array.append(obj);
    }

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    file.write(QJsonDocument(array).toJson(QJsonDocument::Indented));
    file.close();
    return true;
}

const User* UserDatabase::verifyLogin(const QString& name, const QString& password) const
{
    for (const User& user : m_users) {
        if (user.verifyAccount(name, password)) {
            return &user;
        }
    }
    return nullptr;
}

bool UserDatabase::addUser(const User& user)
{
    // 检查重名
    for (const User& u :std::as_const(m_users)) {
        if (u.name == user.name) {
            return false;
        }
    }
    m_users.append(user);
    saveToFile(m_filename);
    return true;
}

bool UserDatabase::updateUserScore(const User& user){
    for ( User& u :m_users) {
        if (u.name == user.name && user.score>u.score) {
            u.score = user.score;
            saveToFile(m_filename);
            return true;
        }
    }
    return false;

}

bool UserDatabase::addUsageTime(const QString& name, int seconds)
{
    for (User& u : m_users) {
        if (u.name == name) {
            if (seconds > 0)
                u.totalUseSeconds += seconds;
            u.sessionCount += 1;
            saveToFile(m_filename);
            return true;
        }
    }
    return false;
}


void UserDatabase::sort(){
    std::sort(m_users.begin(),m_users.end(),
              [](const User& a, const User& b){
                return a.score > b.score;}
              );
}

