#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <QVector>
#include <QString>


class GameLogic{
public:
    GameLogic() = default;
    /// 随机生成4个 1~10 的数
    QVector<int> generateNumbers() const;

    /// 判断这4个数能否（用整型四则运算）算出24
    bool isSolvable(const QVector<int> &nums) const;

    using NumExpr=std::pair<int,QString>;

    ///返回一个解法的表达式
    QString  getSolution(const QVector<int> &nums) const;

    bool findSolution(QVector<NumExpr> nodes, QString &expr) const;

    /**
     * @brief 检查表达式是否只使用了给定的4个数以及合法符号
     * @param expr 玩家输入的表达式
     * @param nums 当前题目的4个数
     * @param error 若失败，返回错误信息
     */
    bool checkUseOfNumbers(const QString &expr,
                           const QVector<int> &nums,
                           QString &error) const;

    /**
     * @brief 解析并计算表达式（只做整数运算）
     * @param expr 中缀表达式字符串
     * @param result 计算结果（整数）
     * @param error 若失败，返回错误信息
     */
    bool evaluateExpr(const QString &expr, int &result, QString &error) const;

    // ---------------- 表达式解析辅助结构 ----------------
    enum TokenType { Number, Op, LParen, RParen };

    /// 表达式中的一个记号
    struct Token {
        TokenType type; ///< 记号类型
        int       value;///< 若是数字，记录数值
        QChar     op;   ///< 若是运算符，记录符号
    };

    /// 字符串切分成记号序列
    bool tokenize(const QString &expr,
                  QVector<Token> &tokens,
                  QString &error) const;

    /// 中缀表达式转为逆波兰式（后缀表达式）
    bool toRPN(const QVector<Token> &tokens,
               QVector<Token> &output,
               QString &error) const;

    /// 计算逆波兰表达式
    bool evalRPN(const QVector<Token> &rpn,
                 int &result,
                 QString &error) const;

    /// 运算符优先级
    int precedence(QChar op) const;


};








#endif // GAME_LOGIC_H
