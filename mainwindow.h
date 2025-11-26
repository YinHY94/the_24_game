#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QDateTime>
#include "UserDatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class GameWidget;
class AdminWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:  
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginBtn_clicked();
    void on_logoutBtn_clicked();
    void on_registerBtn_clicked();
    void on_ruleBtn_clicked();
    void on_rankBtn_clicked();


private:
    Ui::MainWindow *ui;
    static constexpr auto USER_FILE="user.json";
    UserDatabase m_userDb;           // 用户数据管理
    const User* m_currentUser = nullptr;  // 当前登录用户
    QStackedWidget* stackedWidget;
    GameWidget *m_gameWidget = nullptr;
    AdminWidget *m_adminWidget=nullptr;
    QDateTime m_loginTime;


    void initializeUI();
    void UserRegister();
    void UserLogin();
    void UserLogout();
    void updateUIAfterLogin();
    void loadUserDatabase();
    bool verifyUserLogin(const QString& account, const QString& password);

protected:
    // 程序关闭时也统计一次使用时长
    void closeEvent(QCloseEvent *event) override;


};
#endif // MAINWINDOW_H
