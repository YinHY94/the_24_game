#include "AdminWidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QTableWidgetItem>

AdminWidget::AdminWidget(UserDatabase &db,
                         const User &currentUser,
                         QWidget *parent)
    : QWidget(parent)
    , m_db(db)
    , m_admin(currentUser)
{
    setupUi();
    populateTable();
}

void AdminWidget::setupUi()
{
    // 方便在 qss 里单独针对这个根控件写样式
    setObjectName("AdminWidgetRoot");

    // ===== 整体样式：跟 MainWindow/GameWidget 的深色 + 青色风格保持一致 =====
    setStyleSheet(R"(
#AdminWidgetRoot {
    background-color: #1E1E1E;
    color: #F0F0F0;
}

/* 标题 */
QLabel#titleLabel {
    font-size: 22px;
    font-weight: bold;
    color: #00BCD4;
}

/* 当前管理员提示 */
QLabel#adminLabel {
    font-size: 14px;
    color: #94A3B8;
}

/* 表格主体 */
QTableWidget {
    background-color: #111827;
    alternate-background-color: #020617;
    gridline-color: #374151;
    border: 1px solid #374151;
    color: #E5E7EB;
    selection-background-color: rgba(56, 189, 248, 0.35);
    selection-color: #F9FAFB;
}

/* 表头 */
QHeaderView::section {
    background-color: #020617;
    color: #E5E7EB;
    padding: 6px;
    border: none;
    border-bottom: 1px solid #374151;
    font-weight: bold;
}
)");

    // ===== 顶部标题 + 管理员信息 =====
    m_titleLabel = new QLabel(tr("管理员统计面板"), this);
    m_titleLabel->setObjectName("titleLabel");

    m_adminLabel = new QLabel(
        tr("当前管理员：%1").arg(m_admin.name),
        this
        );
    m_adminLabel->setObjectName("adminLabel");

    auto *headerLayout = new QHBoxLayout;
    headerLayout->addWidget(m_titleLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(m_adminLabel);

    // ===== 用户统计表 =====
    m_table = new QTableWidget(this);
    m_table->setColumnCount(6);
    QStringList headers;
    headers << tr("用户名")
            << tr("累计游玩时间")
            << tr("登录次数")
            << tr("简单难度游玩次数")
            << tr("普通难度游玩次数")
            << tr("困难难度游玩次数");
    m_table->setHorizontalHeaderLabels(headers);

    // 表格常用配置
    auto *hHeader = m_table->horizontalHeader();
    hHeader->setStretchLastSection(true);
    hHeader->setSectionResizeMode(QHeaderView::Stretch);

    m_table->verticalHeader()->setVisible(false);
    m_table->setAlternatingRowColors(true);
    m_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_table->setSelectionMode(QAbstractItemView::SingleSelection);
    m_table->setSortingEnabled(true);   // 支持点击表头排序

    // ===== 主布局 =====
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(30, 30, 30, 30);
    mainLayout->setSpacing(20);
    mainLayout->addLayout(headerLayout);
    mainLayout->addWidget(m_table);
}

void AdminWidget::populateTable()
{
    const QVector<User> &users = m_db.users();
    m_table->setRowCount(users.size());

    for (int row = 0; row < users.size(); ++row) {
        const User &u = users[row];

        // 用户名
        auto *itemName = new QTableWidgetItem(u.name);

        // 累计游玩时间（格式化为“X 小时 Y 分钟”）
        auto *itemTime = new QTableWidgetItem(formatDuration(u.totalUseSeconds));

        // 登录次数
        auto *itemSession = new QTableWidgetItem(QString::number(u.sessionCount));

        // 各难度游玩次数（click_time[0/1/2]）
        auto *itemEasy   = new QTableWidgetItem(QString::number(u.click_time[0]));
        auto *itemNormal = new QTableWidgetItem(QString::number(u.click_time[1]));
        auto *itemHard   = new QTableWidgetItem(QString::number(u.click_time[2]));

        // 统一居中对齐
        itemName->setTextAlignment(Qt::AlignCenter);
        itemTime->setTextAlignment(Qt::AlignCenter);
        itemSession->setTextAlignment(Qt::AlignCenter);
        itemEasy->setTextAlignment(Qt::AlignCenter);
        itemNormal->setTextAlignment(Qt::AlignCenter);
        itemHard->setTextAlignment(Qt::AlignCenter);

        m_table->setItem(row, 0, itemName);
        m_table->setItem(row, 1, itemTime);
        m_table->setItem(row, 2, itemSession);
        m_table->setItem(row, 3, itemEasy);
        m_table->setItem(row, 4, itemNormal);
        m_table->setItem(row, 5, itemHard);
    }
}

QString AdminWidget::formatDuration(int totalSeconds) const
{
    if (totalSeconds <= 0) {
        return QStringLiteral("0 小时 0 分钟");
    }
    int hours   = totalSeconds / 3600;
    int minutes = (totalSeconds / 60) % 60;
    return QStringLiteral("%1 小时 %2 分钟")
        .arg(hours)
        .arg(minutes);
}

