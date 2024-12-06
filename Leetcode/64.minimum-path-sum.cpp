/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{
public:
    int mps(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = INT_MAX, right = INT_MAX;
        if (i + 1 < grid.size())
            left = mps(i + 1, j, grid, dp);
        if (j + 1 < grid[0].size())
            right = mps(i, j + 1, grid, dp);

        if (left == INT_MAX and right == INT_MAX)
            return dp[i][j] = grid[i][j];
        else
            return dp[i][j] = grid[i][j] + min(left, right);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, -1));
        return mps(0, 0, grid, dp);
    }
};
// @lc code=end
