/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution
{
public:
    int dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j == t.size() and i == s.size())
            return 1;
        if (i == s.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int first = 0, second = 0;
        if (s[i] == t[j])
            first = dfs(i + 1, j + 1, s, t, dp);
        second = dfs(i + 1, j, s, t, dp);
        return dp[i][j] = first + second;
    }
    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return dfs(0, 0, s, t, dp);
    }
};
// @lc code=end
