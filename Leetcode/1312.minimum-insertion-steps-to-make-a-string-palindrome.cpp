/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution
{
public:
    int solve(int start, int end, string &s, vector<vector<int>> &dp)
    {
        if (start > end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        if (s[start] == s[end])
            return dp[start][end] = solve(start + 1, end - 1, s, dp);

        return dp[start][end] = 1 + min(solve(start + 1, end, s, dp), solve(start, end - 1, s, dp));
    }
    int minInsertions(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return solve(0, s.size() - 1, s, dp);
    }
};
// @lc code=end
