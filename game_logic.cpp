#include "game_logic.h"

#include <QRegularExpression>
#include <QRandomGenerator>


QVector<int> GameLogic::generateNumbers() const
{
    QVector<int> nums(4);
    for (int i = 0; i < 4; ++i) {
        nums[i] = QRandomGenerator::global()->bounded(1, 11); // 1~10
    }
    return nums;
}


bool GameLogic::isSolvable(const QVector<int> &nums) const{
    if (nums.size() == 1) {
        return nums[0] == 24;
    }

    const int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = nums[i];
            int b = nums[j];

            // 剩下的数
            QVector<int> rest;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    rest.push_back(nums[k]);
                }
            }

            QVector<int> candidates;

            // 加
            candidates.push_back(a + b);
            // 减（两个顺序都要考虑）
            candidates.push_back(a - b);
            candidates.push_back(b - a);
            // 乘
            candidates.push_back(a * b);
            // 除（只允许整除）
            if (b != 0 && a % b == 0) {
                candidates.push_back(a / b);
            }
            if (a != 0 && b % a == 0) {
                candidates.push_back(b / a);
            }

            for (int v : candidates) {
                QVector<int> next = rest;
                next.push_back(v);
                if (isSolvable(next)) {
                    return true;
                }
            }
        }
    }
    return false;
}


QString GameLogic::getSolution(const QVector<int> &nums) const{
    QVector<NumExpr> nodes;
    nodes.reserve(nums.size());
    for (int v : nums) {
        NumExpr node;
        node.first = v;
        node.second  = QString::number(v);
        nodes.push_back(node);
    }

    QString solution;
    if (findSolution(nodes,solution)){
        return solution;

    }
    else
        return QString("判断错误：本题理论上可以算出 24，但暂未找到解法。\n本轮游戏结束。");
}


bool GameLogic::findSolution(QVector<NumExpr> nodes, QString &expr) const{
    if (nodes.size() == 1) {
        if (nodes[0].first == 24) {
            expr = nodes[0].second;
            return true;
        }
        return false;
    }

    const int n = nodes.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            NumExpr a = nodes[i];
            NumExpr b = nodes[j];

            // 把没选中的节点放到 rest 里
            QVector<NumExpr> rest;
            rest.reserve(n - 1);
            for (int k = 0; k < n; ++k) {
                if (k != i && k != j) {
                    rest.push_back(nodes[k]);
                }
            }

            QVector<NumExpr> candidates;

            // 加法
            {
                NumExpr c;
                c.first = a.first + b.first;
                c.second  = "(" + a.second + "+" + b.second + ")";
                candidates.push_back(c);
            }

            // 减法：a - b
            {
                NumExpr c;
                c.first = a.first - b.first;
                c.second = "(" + a.second + "-" + b.second + ")";
                candidates.push_back(c);
            }

            // 减法：b - a
            {
                NumExpr c;
                c.first = b.first - a.first;
                c.second  = "(" + b.second + "-" + a.second + ")";
                candidates.push_back(c);
            }

            // 乘法
            {
                NumExpr c;
                c.first = a.first * b.first;
                c.second  = "(" + a.second + "×" + b.second + ")";
                candidates.push_back(c);
            }

            // 除法（只允许整除）
            if (b.first != 0 && a.first % b.first == 0) {
                NumExpr c;
                c.first = a.first / b.first;
                c.second  = "(" + a.second + "÷" + b.second + ")";
                candidates.push_back(c);
            }
            if (a.first != 0 && b.first % a.first == 0) {
                NumExpr c;
                c.first = b.first / a.first;
                c.second  = "(" + b.second + "÷" + a.second + ")";
                candidates.push_back(c);
            }

            // 递归尝试所有候选组合
            for (const NumExpr &c : candidates) {
                QVector<NumExpr> next = rest;
                next.push_back(c);
                if (findSolution(next, expr)) {
                    return true;
                }
            }
        }
    }
    return false;
}


bool GameLogic::checkUseOfNumbers(const QString &expr,
                                     const QVector<int> &nums,
                                     QString &error) const
{
    // 1. 检查非法字符
    for (QChar ch : expr) {
        if (ch.isSpace()) continue;
        if (ch.isDigit()) continue;
        if (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '(' || ch == ')' ||
            ch == u'×' || ch == u'÷' || ch == u'（' || ch == u'）' ) {
            continue;
        }
        error = QString("表达式中包含非法字符：%1。只能使用数字、+ - * × / ÷ 和括号。").arg(ch);
        return false;
    }

    // 2. 提取表达式中出现的所有整数
    QVector<int> exprNums;
    QRegularExpression re("\\d+");
    auto it = re.globalMatch(expr);
    while (it.hasNext()) {
        auto match = it.next();
        exprNums.push_back(match.captured().toInt());
    }

    if (exprNums.size() != nums.size()) {
        error = "表达式中使用的数字个数不是 4 个。";
        return false;
    }

    QVector<int> a = exprNums;
    QVector<int> b = nums;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    if (a != b) {
        error = "表达式中使用的数字与题目给出的 4 个数不一致。";
        return false;
    }

    return true;
}

bool GameLogic::evaluateExpr(const QString &expr,
                                  int &result,
                                  QString &error) const
{
    QVector<Token> tokens;
    if (!tokenize(expr, tokens, error)) {
        return false;
    }

    QVector<Token> rpn;
    if (!toRPN(tokens, rpn, error)) {
        return false;
    }

    if (!evalRPN(rpn, result, error)) {
        return false;
    }
    return true;
}

// ---------------- 表达式解析 ----------------

bool GameLogic::tokenize(const QString &expr,
                            QVector<Token> &tokens,
                            QString &error) const
{
    tokens.clear();
    int i = 0;
    const int n = expr.size();

    while (i < n) {
        QChar ch = expr[i];
        if (ch.isSpace()) {
            ++i;
            continue;
        }

        if (ch.isDigit()) {
            int value = 0;
            while (i < n && expr[i].isDigit()) {
                value = value * 10 + expr[i].digitValue();
                ++i;
            }
            Token t;
            t.type = Number;
            t.value = value;
            tokens.push_back(t);
            continue;
        }

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == u'×' || ch == u'÷') {
            Token t;
            t.type = Op;
            t.op = ch;
            tokens.push_back(t);
            ++i;
            continue;
        }

        if (ch == '(' || ch == u'（') {
            Token t;
            t.type = LParen;
            tokens.push_back(t);
            ++i;
            continue;
        }

        if (ch == ')' || ch == u'）') {
            Token t;
            t.type = RParen;
            tokens.push_back(t);
            ++i;
            continue;
        }

        error = QString("无法识别的字符：%1").arg(ch);
        return false;
    }

    if (tokens.isEmpty()) {
        error = QString("表达式为空。");
        return false;
    }

    return true;
}

int GameLogic::precedence(QChar op) const
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == u'×' || op == u'÷') return 2;
    return 0;
}

bool GameLogic::toRPN(const QVector<Token> &tokens,
                         QVector<Token> &output,
                         QString &error) const
{
    output.clear();
    QVector<Token> stack; // 运算符栈

    for (const Token &t : tokens) {
        if (t.type == Number) {
            output.push_back(t);
        } else if (t.type == Op) {
            while (!stack.isEmpty() &&
                   stack.last().type == Op &&
                   precedence(stack.last().op) >= precedence(t.op)) {
                output.push_back(stack.takeLast());
            }
            stack.push_back(t);
        } else if (t.type == LParen) {
            stack.push_back(t);
        } else if (t.type == RParen) {
            bool foundL = false;
            while (!stack.isEmpty()) {
                Token top = stack.takeLast();
                if (top.type == LParen) {
                    foundL = true;
                    break;
                }
                output.push_back(top);
            }
            if (!foundL) {
                error = QString("括号不匹配。");
                return false;
            }
        }
    }

    while (!stack.isEmpty()) {
        if (stack.last().type == LParen ||
            stack.last().type == RParen) {
            error = QString("括号不匹配。");
            return false;
        }
        output.push_back(stack.takeLast());
    }

    return true;
}

bool GameLogic::evalRPN(const QVector<Token> &rpn,
                           int &result,
                           QString &error) const
{
    QVector<int> stack; // 计算栈

    for (const Token &t : rpn) {
        if (t.type == Number) {
            stack.push_back(t.value);
        } else if (t.type == Op) {
            if (stack.size() < 2) {
                error = QString("表达式格式错误（操作数不足）。");
                return false;
            }
            int b = stack.takeLast();
            int a = stack.takeLast();
            int v = 0;

            if (t.op == '+') {
                v = a + b;
            } else if (t.op == '-') {
                v = a - b;
            } else if (t.op == '*' || t.op == u'×') {
                v = a * b;
            } else if (t.op == '/' || t.op == u'÷') {
                if (b == 0) {
                    error = QString("表达式中出现除以 0。");
                    return false;
                }
                if (a % b != 0) {
                    error =QString("本游戏只允许整数运算，%1 / %2 不是整数。")
                                .arg(a).arg(b);
                    return false;
                }
                v = a / b;
            } else {
                error = QString("未知运算符：%1").arg(t.op);
                return false;
            }
            stack.push_back(v);
        }
    }

    if (stack.size() != 1) {
        error = QString("表达式格式错误。");
        return false;
    }

    result = stack.first();
    return true;
}


