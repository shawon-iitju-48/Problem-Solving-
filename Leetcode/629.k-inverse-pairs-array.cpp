/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            long long sum = 1;
            dp[i][0] = dp[i - 1][0] = 1;
            for (int j = 1; j <= k; j++)
            {
                sum = (sum + dp[i - 1][j]) % MOD;
                if (j >= i)
                    sum = (sum - dp[i - 1][j - i] + MOD) % MOD;
                dp[i][j] = sum % MOD;
            }
        }
        return dp[n][k];
    }
};
// @lc code=end