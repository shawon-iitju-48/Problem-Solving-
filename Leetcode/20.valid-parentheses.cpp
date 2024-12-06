/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        int flag = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[')
                stk.push(s[i]);
            else
            {
                if (stk.empty())
                    flag = 1;
                else
                {
                    char x = stk.top();
                    stk.pop();
                    if ((s[i] == ')' and x != '(') or (s[i] == '}' and x != '{') or (s[i] == ']' and x != '['))
                        flag = 1;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0 and stk.empty())
            return true;
    }
};
// @lc code=end
