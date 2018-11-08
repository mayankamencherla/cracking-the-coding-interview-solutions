/**
 * Given a boolean expression consisting of |, &, ^, and a result
 * Compute all the different ways we can paranthesize the expression
 * To compute the result
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string toString(bool res)
{
    if (res) return "T";

    return "F";
}

unordered_map<string, int> memo;

int computeNumParantheses(string expression, bool result)
{
    if (expression.size() == 0) return 0;

    if (expression.size() == 1) return (result == (stoi(expression) == 1));

    string key = expression + toString(result);

    if (memo.find(key) != memo.end()) return memo[key];

    int ways = 0;

    for (int i=1; i<expression.size(); i += 2)
    {
        char op = expression[i];

        string left = expression.substr(0, i);

        string right = expression.substr(i+1);

        int leftFalse = computeNumParantheses(left, false);

        int leftTrue = computeNumParantheses(left, true);

        int rightFalse = computeNumParantheses(right, false);

        int rightTrue = computeNumParantheses(right, true);

        if (op == '^')
        {
            if (result) ways += leftFalse*rightTrue + leftTrue*rightFalse;

            else ways += leftFalse*rightFalse + leftTrue*rightTrue;
        }
        else if (op == '|')
        {
            if (result) ways += leftFalse*rightTrue + leftTrue*rightFalse + leftTrue*rightTrue;

            else ways += leftFalse*rightFalse;
        }
        else if (op == '&')
        {
            if (result) ways += leftTrue*rightTrue;

            else ways += leftFalse*rightTrue + leftTrue*rightFalse + leftFalse*rightFalse;
        }
    }

    memo[key] = ways;

    return ways;
}

int main()
{
    string expression = "1^0|0|1";

    bool result = false;

    printf("Number of possible solutions to the expression %s resulting in %d is %d\n\n", expression.c_str(), result,
        computeNumParantheses(expression, result));

    expression = "0&0&0&1^1|0";

    result = true;

    printf("Number of possible solutions to the expression %s resulting in %d is %d\n", expression.c_str(), result,
        computeNumParantheses(expression, result));
}
