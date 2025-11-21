#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include "UserDatabase.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:  
    QStackedWidget* stackedWidget;
    QWidget* loginPage;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginBtn_clicked();
    void on_logoutBtn_clicked();
    void on_registerBtn_clicked();



private:
    Ui::MainWindow *ui;
    static constexpr auto USER_FILE="user.json";
    UserDatabase m_userDb;           // 用户数据管理
    const User* m_currentUser = nullptr;  // 当前登录用户

    void initializeUI();
    void UserLogin();
    void UserLogout();
    void updateUIAfterLogin();
    void loadUserDatabase();
    bool verifyUserLogin(const QString& account, const QString& password);


};
#endif // MAINWINDOW_H
