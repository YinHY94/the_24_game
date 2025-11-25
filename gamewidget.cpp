#include "gamewidget.h"
#include "ui_gamewidget.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QRandomGenerator>
#include <QRegularExpression>
#include <QMessageBox>

GameWidget::GameWidget(User currentUser, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget),
    m_currentUser(currentUser),
    m_logic(),
    m_timer(new QTimer(this)),
    m_roundActive(false),
    m_solvable(false),
    m_timeLimit(60),
    m_elapsed(0),
    m_roundIndex(0),
    m_totalScore(0),
    m_lastRoundScore(0)
{
    ui->setupUi(this);
    // 计时器每秒触发一次
    connect(m_timer, &QTimer::timeout,
            this, &GameWidget::onTimerTick);
    connect(ui->m_exprEdit,&QLineEdit::returnPressed,this,&GameWidget::on_m_submitBtn_clicked);
    resetGame();
}

GameWidget::~GameWidget()
{
    delete ui;
}


void GameWidget::resetGame()
{
    m_numbers.clear();
    m_roundActive     = false;
    m_solvable        = false;
    m_elapsed         = 0;
    m_roundIndex      = 0;
    m_totalScore      = 0;
    m_lastRoundScore  = 0;

    ui->m_exprEdit->clear();
    m_timer->stop();

    ui->m_submitBtn->setEnabled(false);
    ui->m_nextBtn->setEnabled(false);

    ui->m_messageLabel->setText(QString("点击“开始游戏”开始第一局。"));
    updateCardsOnUI();
    updateInfoLabels();
}


// void GameWidget::resetForLogout()
// {
//     // 清空当前玩家名
//     m_userName.clear();

//     // 用已有的重置逻辑，把游戏状态全部清空、计时停止
//     resetGame();

//     // // 修改提示信息，强调需要先登录
//     // m_messageLabel->setText(tr("当前未登录，请先登录后再开始游戏。"));

//     // // 更新顶部“玩家：未登录”等信息
//     // updateInfoLabels();
// }


void GameWidget::on_m_startBtn_clicked()
{
    // // 先检查有没有登录
    // if (m_userName.isEmpty()) {
    //     m_messageLabel->setText(tr("当前未登录，请先登录后再开始游戏。"));
    //     return;
    // }

    // 每次开始游戏，相当于重新开一轮三局
    resetGame();
    startRound();
}


void GameWidget::startRound()
{
    if (m_roundIndex >= 3) {
        ui->m_messageLabel->setText(tr("本轮游戏已完成 3 局，请点击“开始游戏”重新开始。"));
        return;
    }

    m_roundIndex++;
    ui->m_exprEdit->clear();
    m_numbers = m_logic.generateNumbers();      // 生成四个数
    m_solvable = m_logic.isSolvable(m_numbers);  // 预先判断是否可算出24

    m_roundActive = true;
    m_elapsed = 0;

    ui->m_submitBtn->setEnabled(true);
    ui->m_nextBtn->setEnabled(false);

    updateCardsOnUI();
    updateInfoLabels();

    ui->m_messageLabel->setText(
        tr("第 %1 局开始！请在限定时间内输入表达式或输入 NO。")
            .arg(m_roundIndex)
        );

    m_timer->start(1000); // 每秒Tick
}

void GameWidget::on_m_submitBtn_clicked()
{
    if (!m_roundActive) {
        return;
    }

    QString expr = ui->m_exprEdit->text().trimmed();
    if (expr.isEmpty()) {
        ui->m_messageLabel->setText(tr("表达式为空，请输入表达式，或者输入 NO。"));
        return;
    }

    // 玩家选择放弃并判断为 NO
    if (expr.compare("NO", Qt::CaseInsensitive) == 0) {
        if (!m_solvable) {
            // 判断正确：确实不能凑出 24
            m_lastRoundScore = calcRoundScore();
            m_totalScore += m_lastRoundScore;
            ui->m_messageLabel->setText(
                tr("判断正确：这题确实不能算出 24。本局得分：%1，总分：%2。")
                    .arg(m_lastRoundScore)
                    .arg(m_totalScore)
                );
            finishRound(false);
        } else {
            // 判断错误：本来可以算出24，却说 NO —— 给出一个示例解法
            QString solution=m_logic.getSolution(m_numbers);
            //if (findSolution24(m_numbers, solution)) {
            ui->m_messageLabel->setText(
                tr("判断错误：本题是可以算出 24 的，例如：%1。\n本轮游戏结束。")
                    .arg(solution)
                );
            // } else {
            //     // 理论上不会走到这里（m_solvable 已经是 true）
            //     m_messageLabel->setText(
            //         tr("判断错误：本题理论上可以算出 24，但暂未找到解法。\n本轮游戏结束。")
            //         );
            //}
            finishRound(true);
        }
        return;
    }

    // 检查表达式是否合法 / 是否只用这四个数
    QString error;
    if (!m_logic.checkUseOfNumbers(expr, m_numbers, error)) {
        ui->m_messageLabel->setText(error);
        return;
    }

    int result = 0;
    if (!m_logic.evaluateExpr(expr, result, error)) {
        ui->m_messageLabel->setText(error);
        return;
    }

    if (result != 24) {
        ui->m_messageLabel->setText(
            QString("表达式计算结果为 %1，并不是 24，请重新输入。").arg(result)
            );
        return;
    }

    // 表达式合法且结果为 24：答对了
    m_lastRoundScore = calcRoundScore();
    m_totalScore += m_lastRoundScore;
    ui->m_messageLabel->setText(
        QString("恭喜，答案正确！本局得分：%1，总分：%2。")
            .arg(m_lastRoundScore)
            .arg(m_totalScore)
        );
    finishRound(false);
}

void GameWidget::on_m_nextBtn_clicked()
{
    startRound();
}

void GameWidget::onTimerTick()
{
    if (!m_roundActive) {
        return;
    }

    ++m_elapsed;
    updateInfoLabels();

    if (m_elapsed >= m_timeLimit) {
        // 超时：本轮游戏结束
        ui->m_messageLabel->setText(tr("超时未作答，本轮游戏结束。"));
        finishRound(true);
    }
}

void GameWidget::finishRound(bool timeoutOrWrong)
{
    m_timer->stop();
    m_roundActive = false;
    ui->m_submitBtn->setEnabled(false);

    // 如果是错误 NO 或者超时，整轮游戏直接结束
    if (timeoutOrWrong) {
        ui->m_nextBtn->setEnabled(false);

        // // ★ 改用：更新排行榜（同一玩家只保留最高分）
        // updateRecords(m_userName, m_totalScore);
        // updateRankLabel();

        //emit gameFinished(m_userName, m_totalScore);
        updateInfoLabels();
        return;
    }

    // 正常结束一局（答对或正确 NO）
    if (m_roundIndex >= 3) {
        // 三局全部完成，本轮结束
        ui->m_nextBtn->setEnabled(false);

        // // ★ 改用：更新排行榜（同一玩家只保留最高分）
        // updateRecords(m_userName, m_totalScore);
        // updateRankLabel();

        ui->m_messageLabel->setText(
            tr("三局已全部完成！本局得分：%1，总分：%2。")
                .arg(m_lastRoundScore)
                .arg(m_totalScore)
            );

        //emit gameFinished(m_userName, m_totalScore);
    } else {
        // 还可以继续下一局
        ui->m_nextBtn->setEnabled(true);
        ui->m_messageLabel->setText(
            tr("第 %1 局回答正确，本局得分：%2，总分：%3。点击“下一题”继续。")
                .arg(m_roundIndex)
                .arg(m_lastRoundScore)
                .arg(m_totalScore)
            );
    }

    updateInfoLabels();
}

void GameWidget::updateInfoLabels()
{
    ui->m_userLabel->setText(
        QString("玩家：%1").arg(m_currentUser.name.isEmpty() ? QString("未登录") : m_currentUser.name)
        );

    if (m_roundIndex == 0) {
        ui->m_roundLabel->setText(QString("第 -- 局"));
    } else {
        ui->m_roundLabel->setText(
            QString("第 %1 局").arg(m_roundIndex)
            );
    }

    int remain = m_roundActive ? (m_timeLimit - m_elapsed) : m_timeLimit;
    if (remain < 0) remain = 0;
    if (m_elapsed== 0 ){
        ui->m_timerLabel->setText(
            QString("剩余时间: -- 秒")
            );
    }
    else {
        ui->m_timerLabel->setText(
            QString("剩余时间：%1 秒").arg(remain)
            );
    }
    ui->m_scoreLabel->setText(
        QString("总分：%1").arg(m_totalScore)
        );

}

void GameWidget::updateCardsOnUI()
{
    if (m_numbers.size()==4){
        QString path = QString(QCoreApplication::applicationDirPath()+"/cards/h%1.png").arg(m_numbers[0]-1);
        QPixmap pix=QPixmap(path);
        ui->m_cardLabels_0->setPixmap(pix.scaled(
            ui->m_cardLabels_0->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));

        path = QString(QCoreApplication::applicationDirPath()+"/cards/s%1.png").arg(m_numbers[1]-1);
        pix=QPixmap(path);
        ui->m_cardLabels_1->setPixmap(pix.scaled(
            ui->m_cardLabels_1->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));

        path = QString(QCoreApplication::applicationDirPath()+"/cards/d%1.png").arg(m_numbers[2]-1);
        pix=QPixmap(path);
        ui->m_cardLabels_2->setPixmap(pix.scaled(
            ui->m_cardLabels_2->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));

        path = QString(QCoreApplication::applicationDirPath()+"/cards/c%1.png").arg(m_numbers[3]-1);
        pix=QPixmap(path);
        ui->m_cardLabels_3->setPixmap(pix.scaled(
            ui->m_cardLabels_3->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));
    }
}

// void GameWidget::updateRankLabel()
// {
//     QString text = tr("高手排行榜（本次运行前3名）：\n");
//     int top = std::min(3, static_cast<int>(m_records.size()));
//     for (int i = 0; i < top; ++i) {
//         text += tr("%1. %2  ——  %3 分\n")
//                     .arg(i + 1)
//                     .arg(m_records[i].name)
//                     .arg(m_records[i].score);
//     }
//     if (top == 0) {
//         text += tr("暂无记录");
//     }
//     m_rankLabel->setText(text);
// }

// void GameWidget::updateRecords(const QString &name, int score)
// {
//     // 统一一下名字，避免空名乱入
//     QString key = name.isEmpty() ? tr("匿名玩家") : name;

//     bool found = false;
//     for (Record &r : m_records) {
//         if (r.name == key) {
//             found = true;
//             // 同一玩家只保留最高分
//             if (score > r.score) {
//                 r.score = score;
//             }
//             break;
//         }
//     }

//     // 如果排行榜里还没有这个玩家，就追加一条
//     if (!found) {
//         Record rec{ key, score };
//         m_records.append(rec);
//     }

//     // 重新按分数从高到低排序
//     std::sort(m_records.begin(), m_records.end(),
//               [](const Record &a, const Record &b){
//                   return a.score > b.score;
//               });
// }

int GameWidget::calcRoundScore() const
{
    // 1. 计分只看“绝对用时”，不看难度的时间上限
    //    这里设定：以 30 秒作为满分参考时间
    const int baseTime = 90;  // 可以根据需要微调，比如 25、40 等

    int t = m_elapsed;        // 实际用时（秒）
    if (t >= baseTime) {
        // 超过参考时间视为 0 分（但游戏本身是否超时由 m_timeLimit 决定）
        return 0;
    }

    // 2. 剩余时间占参考时间的比例（0.0 ~ 1.0）
    double ratio = static_cast<double>(baseTime - t) /
                   static_cast<double>(baseTime);

    // 3. 每题基础满分 1000 分
    const int baseScore = 1000;

    // 4. 难度系数：
    //    简单：1.0 ；普通：1.15 ；困难：1.3
    double difficultyMul = 1.0;
    // switch (m_levelBox->currentIndex()) {
    // case 0: // 简单
    //     difficultyMul = 1.0;
    //     break;
    // case 1: // 普通
    //     difficultyMul = 1.15;
    //     break;
    // case 2: // 困难
    //     difficultyMul = 1.3;
    //     break;
    // default:
    //     difficultyMul = 1.0;
    //     break;
    // }

    // 5. 最终得分：比例 * 基础分 * 难度倍数
    int score = static_cast<int>(ratio * baseScore * difficultyMul + 0.5); // 四舍五入
    if (score < 0) score = 0;
    return score;
}
