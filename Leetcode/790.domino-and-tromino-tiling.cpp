/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int numTilings(int n)
    {
        vector<int> dp(4, 1);
        if (n <= 1)
            return 1;

        dp[2] = 2;
        for (int i = 3; i <= n; i++)
            dp[i % 4] = (2 * dp[(i - 1) % 4] % MOD + dp[(i - 3) % 4]) % MOD;
        return dp[n % 4];
    }
};
// @lc code=end
