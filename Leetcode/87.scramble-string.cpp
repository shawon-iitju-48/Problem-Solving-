/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, bool> dp;
    bool solve(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        string key = s1 + "_" + s2;
        if (dp.count(key))
            return dp[key];

        for (int i = 0; i < s1.size() - 1; i++)
        {
            if (solve(s1.substr(0, i + 1), s2.substr(0, i + 1)) && solve(s1.substr(i + 1), s2.substr(i + 1)))
                return dp[key] = true;

            if (solve(s1.substr(i + 1), s2.substr(0, s1.size() - i - 1)) && solve(s1.substr(0, i + 1), s2.substr(s1.size() - i - 1)))
                return dp[key] = true;
        }

        return dp[key] = false;
    }
    bool isScramble(string s1, string s2)
    {
        return solve(s1, s2);
    }
};
// @lc code=end
