#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include <QStackedWidget>
#include <QPushButton>


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
    void loadUserDatabase();
    void UserLogin();
    bool verifyUserLogin(const QString& account, const QString& password);

private slots:
    void on_loginBtn_clicked();
    void on_cancelBtn_clicked();



private:
    Ui::MainWindow *ui;
    static constexpr auto USER_FILE="user.json";
    QPushButton* logoutBtn;
    const User* currentUser;
    void LoadUserDatabase();
    void UserLogin(QMainWindow* parent);
    QVector<User> userDatabase; // 用户数据库


};
#endif // MAINWINDOW_H
