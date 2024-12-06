/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), mn = INT_MAX;
        vector<int> minLeft(n), minRight(n);

        minLeft[0] = grid[n - 1][0], minRight[n - 1] = grid[n - 1][n - 1];
        for (int i = 1; i < n; i++)
            minLeft[i] = min(minLeft[i - 1], grid[n - 1][i]);
        for (int i = n - 2; i >= 0; i--)
            minRight[i] = min(minRight[i + 1], grid[n - 1][i]);

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int x = INT_MAX, y = INT_MAX;
                if (j - 1 >= 0)
                    x = minLeft[j - 1];
                if (j + 1 < n)
                    y = minRight[j + 1];
                grid[i][j] += min(x, y);
            }
            minLeft[0] = grid[i][0], minRight[n - 1] = grid[i][n - 1];
            for (int j = 1; j < n; j++)
                minLeft[j] = min(minLeft[j - 1], grid[i][j]);
            for (int j = n - 2; j >= 0; j--)
                minRight[j] = min(minRight[j + 1], grid[i][j]);
        }
        for (int i = 0; i < n; i++)
            mn = min(mn, grid[0][i]);
        return mn;
    }
};
// @lc code=end