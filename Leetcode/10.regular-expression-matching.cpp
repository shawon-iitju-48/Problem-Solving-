/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution
{
public:
    int matching(int i, int j, string &s, string &p, unordered_map<string, int> &dp)
    {
        if (i < 0)
        {
            int flag = 0;
            for (int k = j; k >= 0; k--)
            {
                if (p[k] == '*')
                {
                    k = k - 1;
                    continue;
                }
                flag = 1;
            }
            if (flag == 0)
                return 1;
            return 0;
        }
        if (j < 0)
            return 0;
        string key = to_string(i) + "," + to_string(j);
        if (dp.find(key) != dp.end())
            return dp[key];
        if ((s[i] == p[j] or p[j] == '.') and matching(i - 1, j - 1, s, p, dp) == 1)
            return dp[key] = 1;

        if (p[j] == '*' and (s[i] == p[j - 1] or p[j - 1] == '.') and matching(i - 1, j, s, p, dp) == 1)
            return dp[key] = 1;

        if (p[j] == '*' and (s[i] == p[j - 1] or p[j - 1] == '.') and matching(i, j - 2, s, p, dp) == 1)
            return dp[key] = 1;

        if (p[j] == '*' and s[i] != p[j - 1] and matching(i, j - 2, s, p, dp) == 1)
            return dp[key] = 1;

        return dp[key] = 0;
    }
    bool isMatch(string s, string p)
    {
        unordered_map<string, int> dp;
        return matching(s.size() - 1, p.size() - 1, s, p, dp);
    }
};
// @lc code=end
