/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
class Solution
{
public:
    int n, mod = 1e9 + 7;

    int solve(int i, int curr_step, vector<vector<int>> &dp)
    {
        if (i < 0 || i >= n)
            return 0;

        if (curr_step == 0)
            return i == 0 ? 1 : 0;

        if (dp[i][curr_step] != -1)
            return dp[i][curr_step];

        int sum = solve(i, curr_step - 1, dp);
        sum = (sum + solve(i + 1, curr_step - 1, dp)) % mod;
        sum = (sum + solve(i - 1, curr_step - 1, dp)) % mod;

        return dp[i][curr_step] = sum;
    }
    int numWays(int steps, int arrLen)
    {
        n = min(steps, arrLen);
        vector<vector<int>> dp(n, vector<int>(steps + 1, -1));
        return solve(0, steps, dp);
    }
};
// @lc code=end
