// SoundManager.cpp
#include "SoundManager.h"

#include <QMediaPlayer>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QAudioOutput>
#endif
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QUrl>
#include <QDebug>


SoundManager& SoundManager::instance()
{
    static SoundManager g_instance;
    return g_instance;
}

SoundManager::SoundManager(QObject *parent)
    : QObject(parent)
{
    // ---- 背景音乐播放器 ----
    m_bgmPlayer = new QMediaPlayer(this);
    m_bgmOutput = new QAudioOutput(this);
    m_bgmPlayer->setAudioOutput(m_bgmOutput);
    m_bgmOutput->setVolume(0.5f);     // 0.0 ~ 1.0

    // ---- 音效播放器 ----
    m_sfxPlayer = new QMediaPlayer(this);
    m_sfxOutput = new QAudioOutput(this);
    m_sfxPlayer->setAudioOutput(m_sfxOutput);
    m_sfxOutput->setVolume(0.7f);     // 0.0 ~ 1.0

    initPaths();
}

QString SoundManager::basePath() const
{
    // 可执行文件所在目录 + /sounds
    return QCoreApplication::applicationDirPath() + "/sounds";
}

void SoundManager::initPaths()
{
    const QString dir = basePath();

    // ---- BGM 路径 ----
    m_loginBgmPath   = dir + "/login_bgm.ogg";
    m_menuBgmPath    = dir + "/menu_bgm.ogg";
    m_easyBgmPath    = dir + "/easy_bgm.mp3";
    m_normalBgmPath  = dir + "/normal_bgm.mp3";
    m_hardBgmPath    = dir + "/hard_bgm.mp3";
    m_rankBgmPath    = dir + "/rank_bgm.mp3";

    // ---- 音效路径 ----
    m_correctSfxPath     = dir + "/correct.mp3";
    m_stageClearSfxPath  = dir + "/stage_clear.mp3";
    m_failSfxPath        = dir + "/fail.mp3";

#ifdef QT_DEBUG
    auto checkFile = [](const QString &path, const char *name) {
        if (!QFile::exists(path)) {
            qWarning() << "[SoundManager] file not found:" << name << "->" << path;
        }
    };

    checkFile(m_loginBgmPath,   "login_bgm");
    checkFile(m_menuBgmPath,    "menu_bgm");
    checkFile(m_easyBgmPath,    "easy_bgm");
    checkFile(m_normalBgmPath,  "normal_bgm");
    checkFile(m_hardBgmPath,    "hard_bgm");
    checkFile(m_rankBgmPath,    "rank_bgm");
    checkFile(m_correctSfxPath,    "correct_sfx");
    checkFile(m_stageClearSfxPath, "stage_clear_sfx");
    checkFile(m_failSfxPath,       "fail_sfx");
#endif
}

void SoundManager::switchBgm(const QString &filePath)
{
    if (filePath.isEmpty())
        return;

    if (!QFile::exists(filePath)) {
        qWarning() << "[SoundManager] BGM file not exists:" << filePath;
        return;
    }

    m_bgmPlayer->stop();

    m_bgmPlayer->setSource(QUrl::fromLocalFile(filePath));
    m_bgmPlayer->setLoops(QMediaPlayer::Infinite);  // 无限循环

    m_bgmPlayer->play();
}

void SoundManager::playSfx(const QString &filePath)
{
    if (filePath.isEmpty())
        return;

    if (!QFile::exists(filePath)) {
        qWarning() << "[SoundManager] SFX file not exists:" << filePath;
        return;
    }

    // 同一时间只播一个音效：先停，再重新设置并播放
    m_sfxPlayer->stop();

    m_sfxPlayer->setSource(QUrl::fromLocalFile(filePath));
    m_sfxPlayer->setLoops(1);

    m_sfxPlayer->play();
}

void SoundManager::playLoginBgm()
{
    switchBgm(m_loginBgmPath);
}

void SoundManager::playMenuBgm()
{
    switchBgm(m_menuBgmPath);
}

void SoundManager::playGameBgm(Difficulty difficultyLevel)
{
    switch (difficultyLevel) {
    case Easy: // Easy
        switchBgm(m_easyBgmPath);
        break;
    case Normal: // Normal
        switchBgm(m_normalBgmPath);
        break;
    case Hard: // Hard
        switchBgm(m_hardBgmPath);
        break;
    default:
        switchBgm(m_easyBgmPath);
        break;
    }
}

void SoundManager::playRankBgm()
{
    switchBgm(m_rankBgmPath);
}

void SoundManager::stopBgm()
{
    m_bgmPlayer->stop();
}

void SoundManager::playCorrectSfx()
{
    playSfx(m_correctSfxPath);
}

void SoundManager::playStageClearSfx()
{
    playSfx(m_stageClearSfxPath);
}

void SoundManager::playFailSfx()
{
    playSfx(m_failSfxPath);
}

