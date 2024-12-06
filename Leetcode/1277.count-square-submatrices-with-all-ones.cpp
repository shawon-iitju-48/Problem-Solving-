/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution
{
public:
    // right, bottom, diag
    int sum = 0;
    unordered_map<int, unordered_map<int, vector<int>>>dp;
    vector<int> solve(int i, int j, vector<vector<int>> &matrix)
    {
        if (i >= matrix.size() or j >= matrix[0].size())
            return {0, 0, 0};
        
        if(dp[i].count(j))
        return dp[i][j];

        int right = solve(i, j + 1, matrix)[0];
        int bottom = solve(i + 1, j, matrix)[1];
        int diag = solve(i + 1, j + 1, matrix)[2];

        if (matrix[i][j] == 0)
            return dp[i][j]={0, 0, 0};

        sum += 1 + min({right, bottom, diag});

        return dp[i][j]={right + 1, bottom + 1, diag + 1};
    }
    int countSquares(vector<vector<int>> &matrix)
    {
        solve(0, 0, matrix);
        return sum;
    }
};
// @lc code=end
