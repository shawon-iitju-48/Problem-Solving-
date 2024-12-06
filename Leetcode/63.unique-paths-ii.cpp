/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
public:
    int dp[101][101], m, n;
    int solve(int i, int j, vector<vector<int>> &obstacleGrid)
    {
        if (i == m - 1 and j == n - 1)
            return 1 - obstacleGrid[m - 1][n - 1];

        if (dp[i][j] != -1)
            return dp[i][j];

        if (obstacleGrid[i][j] == 1)
            return 0;

        int count = 0;
        if (i + 1 < m and obstacleGrid[i + 1][j] == 0)
            count += solve(i + 1, j, obstacleGrid);

        if (j + 1 < n and obstacleGrid[i][j + 1] == 0)
            count += solve(i, j + 1, obstacleGrid);

        return dp[i][j] = count;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, obstacleGrid);
    }
};
// @lc code=end
