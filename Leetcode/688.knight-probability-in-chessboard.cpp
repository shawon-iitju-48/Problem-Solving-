/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution
{
public:
    int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
    int dp[25][25][101];
    double solve(int i, int j, int k, int &n)
    {
        if (i < 0 or j < 0 or i >= n or j >= n)
            return 0;

        if (k == 0)
            return 1;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        double cnt = 0;
        for (int x = 0; x < 8; x++)
        {
            int nx = i + dx[x];
            int ny = j + dy[x];
            cnt += solve(nx, ny, k - 1, n);
        }
        return dp[i][j][k] = cnt;
    }
    double knightProbability(int n, int k, int row, int column)
    {
        memset(dp, -1, sizeof(dp));
        double ans = solve(row, column, k, n);

        for (int i = 1; i <= k; i++)
            ans = ans / 8.0;
        return ans;
    }
};
// @lc code=end
