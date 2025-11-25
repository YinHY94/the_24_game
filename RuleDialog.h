#ifndef RULEDIALOG_H
#define RULEDIALOG_H

#include <QDialog>

// 前置声明，减少头文件依赖，提高编译速度
QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
QT_END_NAMESPACE


class RuleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RuleDialog(QWidget *parent = nullptr);
    ~RuleDialog() override = default;

private:
    QPushButton *m_okBtn;         // 确定按钮
    QLabel      *m_ruleLabel;
};


#endif // RULEDIALOG_H
