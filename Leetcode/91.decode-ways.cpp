/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int decode(int i, string &s, vector<int> &dp)
    {
        if (i >= s.size())
            return 1;

        if (dp[i] != -1)
            return dp[i];

        if (s[i] == '0')
            return 0;

        int first = decode(i + 1, s, dp), second = 0;
        if (i + 1 < s.size() and stoi(s.substr(i, 2)) <= 26)
            second = decode(i + 2, s, dp);

        return dp[i] = (first + second);
    }
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 2, -1);
        return decode(0, s, dp);
    }
};
// @lc code=end
