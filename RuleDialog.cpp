#include "RuleDialog.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

RuleDialog::RuleDialog(QWidget *parent)
    : QDialog(parent)
    , m_okBtn(new QPushButton("确定", this))
    , m_ruleLabel(new QLabel(this))  // 改为成员变量，才能在外面设置样式
{
    setWindowTitle("游戏规则");
    setMinimumSize(460, 360);
    setMaximumSize(460, 360);

    // === 主题背景设置 ===
    setStyleSheet("background: #1E1E1E;");  // **深色背景匹配主题**

    // === 标题 ===
    auto *titleLabel = new QLabel("24 点游戏规则", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet(
        "font-size: 24px; "              // 略微调大标题字体
        "font-weight: bold; "
        "color: #00BCD4; "               // **青色强调色**
        "margin: 20px 0 15px 0;"
        );

    // === 规则文字（自动换行 + 更好阅读）===
    m_ruleLabel->setText(
        // **文字颜色改为浅色 #F0F0F0**
        "<p style='line-height: 180%; color: #F0F0F0; font-size: 15px;'>"
        "<b>计分规则：</b><br>"
        "每局游戏在规定时间内<b>正确算出24</b>或正确判断“<b>NO</b>”，可获得 "
        // **高亮色改为青色 #00BCD4**
        "<b style='color:#00BCD4;'>(100 − t) × n</b> 分数<br><br>"
        "• t = 所用时间（秒）<br>"
        "• n = 难度倍率（简单 1.00｜普通 1.05｜困难 1.10）<br><br>"
        "若<b>超时</b>、或<b>能算出24却误判NO</b>，本局得 "
        // **警告色改为橙色 #FBBF24**
        "<span style='color:#FBBF24;'>0分</span><br><br>"
        "三局结束后，总分 = 三局得分之和"
        "</p>"
        );
    m_ruleLabel->setWordWrap(true);        // 关键！自动换行
    m_ruleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_ruleLabel->setContentsMargins(30, 0, 30, 20);

    // === 确定按钮（青色强调）===
    m_okBtn->setFixedHeight(40);
    m_okBtn->setCursor(Qt::PointingHandCursor);
    m_okBtn->setStyleSheet(
        "QPushButton {"
        "   background: #00BCD4; color: #1E1E1E; border: none; border-radius: 8px;" // **青色背景，深色文字**
        "   font-size: 15px; font-weight: bold; padding: 0 30px;"
        "}"
        "QPushButton:hover { background: #00E5FF; }" // **悬停亮青色**
        "QPushButton:pressed { background: #00A6B8; }" // **按下深青色**
        );

    // === 按钮布局（居中）===
    auto *btnLayout = new QHBoxLayout();
    btnLayout->addStretch();
    btnLayout->addWidget(m_okBtn);
    btnLayout->addStretch();

    // === 主布局 ===
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(m_ruleLabel);
    mainLayout->addStretch();        // 让按钮靠下
    mainLayout->addLayout(btnLayout);
    mainLayout->setContentsMargins(20, 10, 20, 25);


    // === 信号槽 ===
    connect(m_okBtn, &QPushButton::clicked, this, &QDialog::accept);
    // 支持回车关闭
    m_okBtn->setDefault(true);
}
