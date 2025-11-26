#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QVector>
#include <QString>
#include "user.h"
#include "game_logic.h"

class QLabel;
class QLineEdit;
class QPushButton;
class QComboBox;
class QTimer;
class UserDatabase;


namespace Ui {
class GameWidget;
}


enum Difficulty{
    Easy,
    Normal,
    Hard
};

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(UserDatabase& m_userDb,User currentUser,QWidget *parent = nullptr);
    ~GameWidget();


    bool        m_gameActive;

    /**
     * @brief 设置当前登录玩家名称（从登录界面传进来）
     * @param name 玩家名字
     */
    void setCurrentUserName(const QString &name);

    /// 退出登录时调用：停止当前游戏并重置为未登录状态
    void resetForLogout();



private slots:
    /// 点击“开始游戏”按钮
    void on_m_startBtn_clicked();

    /// 点击“提交答案”按钮
    void on_m_submitBtn_clicked();

    /// 点击“下一题”按钮
    void on_m_nextBtn_clicked();

    void on_m_hintBtn_clicked();

    /// 计时器每秒触发一次
    void onTimerTick();


private:
    Ui::GameWidget *ui;

    QTimer      *m_timer;         ///< 每秒计时器

    // ---------------- 游戏状态数据 ----------------
    UserDatabase& m_userDatabase;
    User        m_currentUser;
    GameLogic   m_logic;
    QVector<int> m_numbers;       ///< 当前题目的4个数
    Difficulty   m_difficulty;
    bool        m_roundActive;    ///< 当前是否处于答题中
    bool        m_solvable;       ///< 当前4个数是否能算出24
    bool        m_hintUsed;
    int         m_timeLimit;      ///< 当前题目的时间上限（秒）
    int         m_elapsed;        ///< 已用时间（秒）
    int         m_roundIndex;     ///< 当前是第几局（1~3），0表示还没开始
    int         m_totalScore;     ///< 本轮游戏总分
    int         m_lastRoundScore; ///< 最近一局的得分


    void chooseDifficulty();

    /// 重置整个游戏状态（用于“开始游戏”之前）
    void resetGame();

    void startGame();

    /// 开始下一局（最多3局）
    void startRound();

    /**
     * @brief 结束当前局
     * @param timeoutOrWrong 为 true 时，表示超时或严重错误（例如 NO 判断错），本轮游戏直接结束
     */
    void finishRound(bool timeoutOrWrong);

    /// 更新顶部信息：玩家名、局数、剩余时间、总分
    void updateInfoLabels();

    /// 把 m_numbers 显示到四个牌面上
    void updateCardsOnUI();

    // /// 更新排行榜显示（Top 3）
    // void updateRankLabel();

    // /// 将本次成绩更新到排行榜：同一玩家只保留最高分
    // void updateRecords(const QString &name, int score);

    /// 根据当前耗时和难度计算本局得分
    int calcRoundScore() const;

};

#endif // GAMEWIDGET_H
