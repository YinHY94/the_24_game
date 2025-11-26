#include "gamewidget.h"
#include "UserDatabase.h"
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
#include "difficultydialog.h"
#include "rankingdialog.h"
#include "SoundManager.h"

GameWidget::GameWidget(UserDatabase& m_userDb,User currentUser, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget),
    m_userDatabase(m_userDb),
    m_currentUser(currentUser),
    m_logic(),
    m_timer(new QTimer(this)),
    m_roundActive(false),
    m_gameActive(false),
    m_solvable(false),
    m_hintUsed(false),
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
    ui->m_exprEdit->setEnabled(m_roundActive);
    m_timer->stop();

    ui->m_submitBtn->setEnabled(false);
    ui->m_nextBtn->setEnabled(false);
    ui->m_hintBtn->setEnabled(false);

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

void GameWidget::startGame(){
    resetGame();
    chooseDifficulty();
    startRound();
    m_gameActive=true;
    m_hintUsed=false;
    // 【开始游戏】
    ui->m_startBtn->setText("结束游戏");

    // 红色样式（完美适配你现在的深色主题）
    ui->m_startBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: #ef4444; color: white; "  // 红色背景，白字
        "   border-radius: 6px; font-weight: bold; padding: 10px 20px;"
        "}"
        "QPushButton:hover { background-color: #dc2626; }"
        "QPushButton:pressed { background-color: #b91c1c; }"
        );
}


void GameWidget::on_m_startBtn_clicked()
{


    if (!m_gameActive ) {
        // 每次开始游戏，相当于重新开一轮三局
        startGame();
    } else {
        finishRound(true);
        ui->m_messageLabel->setText(QString("游戏结束，点击“开始游戏”开始新一局。"));
    }

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
    ui->m_exprEdit->setEnabled(m_roundActive);
    m_elapsed = 0;

    ui->m_submitBtn->setEnabled(true);
    if (!m_hintUsed){
        ui->m_hintBtn->setEnabled(true);
    }
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
    ui->m_exprEdit->setEnabled(m_roundActive);
    ui->m_submitBtn->setEnabled(false);
    ui->m_hintBtn->setEnabled(false);

    // 如果是错误 NO 或者超时，整轮游戏直接结束
    if (timeoutOrWrong) {
        ui->m_nextBtn->setEnabled(false);
        ui->m_startBtn->setText("开始游戏");
        m_gameActive=false;
        // 恢复原始青色样式
        ui->m_startBtn->setStyleSheet(
            "QPushButton {"
            "   background-color: #00BCD4; color: #1E1E1E; "
            "   border-radius: 6px; font-weight: bold; padding: 10px 20px;"
            "}"
            "QPushButton:hover { background-color: #00E5FF; }"
            "QPushButton:pressed { background-color: #00A6B8; }"
            );
        if (m_totalScore > m_currentUser.score){
            m_currentUser.score=m_totalScore;
        }
        m_userDatabase.updateUserScore(m_currentUser);
        SoundManager::instance().playFailSfx();
        SoundManager::instance().playMenuBgm();


    }

    // 正常结束一局（答对或正确 NO）
    else if (m_roundIndex >= 3) {
        // 三局全部完成，本轮结束
        ui->m_nextBtn->setEnabled(false);
        m_gameActive=false;
        // // ★ 改用：更新排行榜（同一玩家只保留最高分）
        // updateRecords(m_userName, m_totalScore);
        // updateRankLabel();
        ui->m_startBtn->setText("开始游戏");

        // 恢复原始青色样式
        ui->m_startBtn->setStyleSheet(
            "QPushButton {"
            "   background-color: #00BCD4; color: #1E1E1E; "
            "   border-radius: 6px; font-weight: bold; padding: 10px 20px;"
            "}"
            "QPushButton:hover { background-color: #00E5FF; }"
            "QPushButton:pressed { background-color: #00A6B8; }"
            );


        ui->m_messageLabel->setText(
            tr("三局已全部完成！本局得分：%1，总分：%2。")
                .arg(m_lastRoundScore)
                .arg(m_totalScore)
            );
        if (m_totalScore > m_currentUser.score){
            m_currentUser.score=m_totalScore;
        }
        m_userDatabase.updateUserScore(m_currentUser);

        SoundManager::instance().playStageClearSfx();
        SoundManager::instance().playMenuBgm();

    } else {
        // 还可以继续下一局
        ui->m_nextBtn->setEnabled(true);
        ui->m_messageLabel->setText(
            tr("第 %1 局回答正确，本局得分：%2，总分：%3。点击“下一局”继续。")
                .arg(m_roundIndex)
                .arg(m_lastRoundScore)
                .arg(m_totalScore)
            );
        SoundManager::instance().playCorrectSfx();
    }
    m_numbers.clear();
    updateCardsOnUI();
    updateInfoLabels();
    ui->m_exprEdit->clear();
}

void GameWidget::updateInfoLabels()
{
    ui->m_userLabel->setText(
        QString("玩家：%1").arg(m_currentUser.name.isEmpty() ? QString("未登录") : m_currentUser.name)
        );

    if (m_roundActive==false) {
        ui->m_roundLabel->setText(QString("第 -- 局"));
    } else {
        ui->m_roundLabel->setText(
            QString("第 %1 局").arg(m_roundIndex)
            );
    }

    int remain = m_roundActive ? (m_timeLimit - m_elapsed) : m_timeLimit;
    if (remain < 0) remain = 0;
    if (!m_roundActive){
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
    else{
        QString path = QString(QCoreApplication::applicationDirPath()+"/cards/null.png");
        QPixmap pix=QPixmap(path);
        ui->m_cardLabels_0->setPixmap(pix.scaled(
            ui->m_cardLabels_0->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));

        ui->m_cardLabels_1->setPixmap(pix.scaled(
            ui->m_cardLabels_1->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));

        ui->m_cardLabels_2->setPixmap(pix.scaled(
            ui->m_cardLabels_2->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));

        ui->m_cardLabels_3->setPixmap(pix.scaled(
            ui->m_cardLabels_3->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation));
    }
}



int GameWidget::calcRoundScore() const
{
    // 1. 参考时间：90秒
    // const int baseTime = 90;

    int t = m_elapsed;        // 实际用时
    // if (t >= baseTime) {
    //     return 0;
    // }

    // 2. 剩余时间占参考时间的比例（0.0 ~ 1.0）
    // double ratio = static_cast<double>(baseTime - t) /
    //                static_cast<double>(baseTime);

    // 2. 定义比例，即每秒用时所扣分数
    double ratio = 1.0;

    // 3. 每题基础满分 100 分
    const int baseScore = 100;

    // 4. 难度系数：
    //   简单：1.0 ；普通：1.05 ；困难：1.1
    double difficultyMul = 1.0;
    switch (m_difficulty) {
    case Easy: // 简单
        difficultyMul = 1.0;
        break;
    case Normal: // 普通
        difficultyMul = 1.05;
        break;
    case Hard: // 困难
        difficultyMul = 1.1;
        break;
    default:
        difficultyMul = 1.0;
        break;
    }

    // 4. 最终得分：基础满分-时间用时*比例
    int score = static_cast<int>((baseScore - t * ratio) * difficultyMul + 0.5); // 四舍五入


    if (score < 0) score = 0;
    return score;
}


void GameWidget::chooseDifficulty(){
    DifficultyDialog dialog(m_difficulty,this);
    if (dialog.exec() != QDialog::Accepted) {
        return;
    }
    SoundManager::instance().playGameBgm(m_difficulty);
    switch (m_difficulty){
        case Easy:
            m_timeLimit=90;
            break;
        case Normal:
            m_timeLimit=60;
            break;
        case Hard:
            m_timeLimit=30;
            break;

    }
    m_currentUser.click_time[m_difficulty]++;

}


void GameWidget::on_m_hintBtn_clicked(){
    // 1. 非答题状态下不处理
    if (!m_roundActive) {
        return;
    }

    // 2. 已经用过提示（理论上按钮已经禁用，这里双保险）
    if (m_hintUsed) {
        ui->m_messageLabel->setText(tr("本轮已经使用过提示，无法再次使用。"));
        ui->m_hintBtn->setEnabled(false);
        return;
    }

    // 3. 标记为本轮已使用提示，并禁用按钮
    m_hintUsed = true;
    ui->m_hintBtn->setEnabled(false);

    // 4. 根据当前题目是否可解，执行不同的提示策略
    if (m_solvable) {
        // ---------- 情况一：本题可算出 24，给出“挖去数字”的算式 ----------
        QString solution = m_logic.getSolution(m_numbers);  // 完整解法表达式

        if (solution.isEmpty()) {
            // 理论上不会为空，防御性处理
            ui->m_messageLabel->setText(tr("提示：本题可以算出 24，但暂时无法提供具体解法，请继续尝试。"));
            return;
        }

        // 挖去数字：所有数字字符用下划线代替，只保留运算符和括号
        QString hintExpr = solution;
        QRegularExpression digitRe("\\d");   // 每一个数字字符
        hintExpr.replace(digitRe, "_");

        // 把“模板表达式”放入输入框，方便玩家在此基础上填数字
        ui->m_exprEdit->setText(hintExpr);

        ui->m_messageLabel->setText(
            tr("提示：本题可以算出 24，其中一种算式是：%1\n"
               "(下划线表示被挖去的数字，请你根据当前四张牌自行填入。)")
                .arg(hintExpr)
            );
    } else {
        // ---------- 情况二：本题无解，直接帮玩家换一组牌 ----------
        ui->m_messageLabel->setText(
            tr("提示：当前这组牌无法算出 24，已为你更换一组新牌，请继续作答。")
            );

        // 重新生成一组新题，但仍算同一局，时间继续走
        m_numbers   = m_logic.generateNumbers();
        m_solvable  = m_logic.isSolvable(m_numbers);
        m_elapsed = 0;
        ui->m_exprEdit->clear();
        updateCardsOnUI();
        updateInfoLabels();
    }

}


