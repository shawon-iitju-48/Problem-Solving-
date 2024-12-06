/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int climbit(int n, vector<int> &dp)
    {
        if (n <= 0)
            return n + 1;
        if (dp[n] != 0)
            return dp[n];
        dp[n] = climbit(n - 1, dp) + climbit(n - 2, dp);
        return dp[n];
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        return climbit(n, dp);
    }
};
// @lc code=end
