#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QObject>
#include <QString>

#include "gamewidget.h"

class QMediaPlayer;
class QAudioOutput;

/// 全局音频管理器（单例）
class SoundManager : public QObject
{
    Q_OBJECT
public:
    /// 获取全局唯一实例
    static SoundManager& instance();

    /// 登录/欢迎界面 BGM
    void playLoginBgm();

    /// 游戏主界面（登录后、开始游戏前，选难度界面）BGM
    void playMenuBgm();

    /// 按难度播放对局中的 BGM
    /// difficultyLevel: 0 = Easy, 1 = Normal, 2 = Hard
    void playGameBgm(Difficulty difficultyLevel);

    /// 排行榜 BGM
    void playRankBgm();

    /// 停止当前 BGM
    void stopBgm();

    /// 前两局答对的“正确”音效
    void playCorrectSfx();

    /// 第三局通关音效
    void playStageClearSfx();

    /// 答错 / 超时 / 主动结束 的失败音效
    void playFailSfx();

    /// 使用提示音效
    void playHintSfx();

private:
    explicit SoundManager(QObject *parent = nullptr);

    void initPaths();
    QString basePath() const;

    void switchBgm(const QString &filePath);
    void playSfx(const QString &filePath);

    // ---- 背景音乐播放器 ----
    QMediaPlayer *m_bgmPlayer = nullptr;
    QAudioOutput *m_bgmOutput = nullptr;   ///< Qt6 使用，Qt5 下保持 nullptr

    // ---- 音效播放器 ----
    QMediaPlayer *m_sfxPlayer = nullptr;
    QAudioOutput *m_sfxOutput = nullptr;

    // ---- 各种 BGM 路径 ----
    QString m_loginBgmPath;
    QString m_menuBgmPath;
    QString m_easyBgmPath;
    QString m_normalBgmPath;
    QString m_hardBgmPath;
    QString m_rankBgmPath;    ///< 预留排行榜 BGM

    // ---- 音效路径 ----
    QString m_correctSfxPath;
    QString m_stageClearSfxPath;
    QString m_failSfxPath;
    QString m_hintSfxPath;
};



#endif // SOUNDMANAGER_H
