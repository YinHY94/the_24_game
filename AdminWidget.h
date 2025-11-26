#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H


#include <QWidget>
#include "UserDatabase.h"   // 里边已经包含 User 定义

QT_BEGIN_NAMESPACE
class QTableWidget;
class QLabel;
QT_END_NAMESPACE

/**
 * @brief 管理员页面：展示所有用户的统计信息
 * 显示列：
 *  - 用户名
 *  - 累计游玩时长（小时/分钟）
 *  - 登录次数
 *  - 简单难度游玩次数
 *  - 普通难度游玩次数
 *  - 困难难度游玩次数
 */
class AdminWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AdminWidget(UserDatabase &db,
                         const User &currentUser,
                         QWidget *parent = nullptr);

    ~AdminWidget() override = default;

private:
    UserDatabase &m_db;      ///< 引用整个用户数据库
    User          m_admin;   ///< 当前登录的管理员（拷贝即可）

    QLabel       *m_titleLabel   = nullptr;
    QLabel       *m_adminLabel   = nullptr;
    QTableWidget *m_table        = nullptr;

    void setupUi();          ///< 创建界面 & 设置样式
    void populateTable();    ///< 把所有用户数据填到表格
    QString formatDuration(int totalSeconds) const;  ///< 秒 -> “X 小时 Y 分钟”
};


#endif // ADMINWIDGET_H
