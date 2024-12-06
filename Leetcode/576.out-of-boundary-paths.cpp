/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution
{
public:
    int m, n, MOD = 1e9 + 7, dp[51][51][51];
    int solve(int i, int j, int move)
    {
        if (i < 0 or j < 0 or i >= m or j >= n)
            return 1;

        if (move == 0)
            return 0;

        if (dp[i][j][move] != -1)
            return dp[i][j][move];

        int cnt = solve(i + 1, j, move - 1);
        cnt = (cnt + solve(i, j + 1, move - 1)) % MOD;
        cnt = (cnt + solve(i - 1, j, move - 1)) % MOD;
        cnt = (cnt + solve(i, j - 1, move - 1)) % MOD;

        return dp[i][j][move] = cnt;
    }
    int findPaths(int mm, int nn, int maxMove, int startRow, int startColumn)
    {
        m = mm, n = nn;
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, maxMove);
    }
};
// @lc code=end
