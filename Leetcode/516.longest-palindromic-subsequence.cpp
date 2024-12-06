/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution
{
public:
    int solve(int start, int end, string &s, vector<vector<int>> &dp)
    {
        if (start > end)
            return 0;

        if (start == end)
            return 1;

        if (dp[start][end] != -1)
            return dp[start][end];

        if (s[start] == s[end])
            return dp[start][end] = 2 + solve(start + 1, end - 1, s, dp);

        return dp[start][end] = max(solve(start, end - 1, s, dp), solve(start + 1, end, s, dp));
    }
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return solve(0, s.size() - 1, s, dp);
    }
};
// @lc code=end
