/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */

// @lc code=start
class Solution
{
public:
    int low, high, zero, one, MOD = 1e9 + 7;
    int solve(int current_length, vector<int> &dp)
    {
        if (current_length > high)
            return 0;

        if (dp[current_length] != -1)
            return dp[current_length];

        int cnt = (current_length >= low) ? 1 : 0;
        cnt = (cnt + solve(current_length + zero, dp)) % MOD;
        cnt = (cnt + solve(current_length + one, dp)) % MOD;

        return dp[current_length] = cnt;
    }
    int countGoodStrings(int l, int h, int z, int o)
    {
        low = l, high = h, zero = z, one = o;
        vector<int> dp(high + 1, -1);
        return solve(0, dp);
    }
};
// @lc code=end
