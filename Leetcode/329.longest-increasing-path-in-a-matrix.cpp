/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution
{
public:
    int lip(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        int m = matrix.size(), n = matrix[0].size();
        int mx = 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i - 1 >= 0 and matrix[i - 1][j] > matrix[i][j])
            mx = max(mx, 1 + lip(i - 1, j, matrix, dp));

        if (i + 1 < m and matrix[i + 1][j] > matrix[i][j])
            mx = max(mx, 1 + lip(i + 1, j, matrix, dp));

        if (j - 1 >= 0 and matrix[i][j - 1] > matrix[i][j])
            mx = max(mx, 1 + lip(i, j - 1, matrix, dp));

        if (j + 1 < n and matrix[i][j + 1] > matrix[i][j])
            mx = max(mx, 1 + lip(i, j + 1, matrix, dp));

        return dp[i][j] = mx;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int mx = 1;
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, -1));
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                mx = max(mx, lip(i, j, matrix, dp));

        return mx;
    }
};
// @lc code=end
