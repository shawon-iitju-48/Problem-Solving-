/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;
    void gen(int open, int close, string s, int n)
    {
        if (open == n and close == n)
        {
            ans.push_back(s);
            return;
        }
        if (open == close or open <= n)
            gen(open + 1, close, s + "(", n);
        if (open > close and close <= n)
            gen(open, close + 1, s + ")", n);
    }

    vector<string> generateParenthesis(int n)
    {
        gen(0, 0, "", n);
        return ans;
    }
};
// @lc code=end
