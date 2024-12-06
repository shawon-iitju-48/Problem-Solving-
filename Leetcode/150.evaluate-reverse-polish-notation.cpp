/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        int a, b;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/")
            {
                a = stk.top(), stk.pop();
                b = stk.top(), stk.pop();
                if (tokens[i] == "+")
                    stk.push(b + a);
                if (tokens[i] == "-")
                    stk.push(b - a);
                if (tokens[i] == "*")
                    stk.push(b * a);
                if (tokens[i] == "/")
                    stk.push(b / a);
            }
            else
                stk.push(stoi(tokens[i]));
        }
        return stk.top();
    }
};
// @lc code=end
