/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution
{
public:
    int MOD = 1e9 + 7, k, dp[31][1001];
    int solve(int n, int currSum)
    {
        if (currSum == 0 and n == 0)
            return 1;
        if (n == 0 or currSum < 0)
            return 0;

        if (dp[n][currSum] != -1)
            return dp[n][currSum];

        int cnt = 0;
        for (int i = 1; i <= k; i++)
            cnt = (cnt + solve(n - 1, currSum - i)) % MOD;

        return dp[n][currSum] = cnt;
    }
    int numRollsToTarget(int n, int kk, int target)
    {
        k = kk;
        memset(dp, -1, sizeof(dp));
        return solve(n, target);
    }
};
// @lc code=end
