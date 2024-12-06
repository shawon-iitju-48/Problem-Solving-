/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minpq;
        
        res[0][0] = 0;
        minpq.push({0, 0, 0});
        while (!minpq.empty())
        {
            int i = minpq.top()[1], j = minpq.top()[2], lev = minpq.top()[0];
            minpq.pop();
            for (int d = 0; d < 4; d++)
            {
                int newi = i + directions[d][0];
                int newj = j + directions[d][1];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n &&
                    max(lev, abs(heights[i][j] - heights[newi][newj])) < res[newi][newj])
                {
                    res[newi][newj] = max(lev, abs(heights[i][j] - heights[newi][newj]));
                    minpq.push({res[newi][newj], newi, newj});
                }
            }
        }
        return res[m - 1][n - 1];
    }
};
// @lc code=end
