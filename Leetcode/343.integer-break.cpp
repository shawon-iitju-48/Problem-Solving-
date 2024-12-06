/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution
{
public:
    int dp[100];
    int solve(int n)
    {
        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int mx = 0;
        for (int i = 1; i < n; i++)
            mx = max(mx, max(i * solve(n - i), i * (n - i)));

        return dp[n] = mx;
    }
    int integerBreak(int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
// @lc code=end
