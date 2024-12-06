/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int traverse(vector<vector<int>> &a, int row, int col, int m, int n)
    {
        if (row == m - 1 and col == n - 1)
            return a[row][col] = 1;

        if (a[row][col] != -1)
            return a[row][col];

        int sum = 0;
        if (row + 1 < m)
            sum += traverse(a, row + 1, col, m, n);

        if (col + 1 < n)
            sum += traverse(a, row, col + 1, m, n);

        return a[row][col] = sum;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> a(m, vector<int>(n, -1));
        return traverse(a, 0, 0, m, n);
    }
};
// @lc code=end
