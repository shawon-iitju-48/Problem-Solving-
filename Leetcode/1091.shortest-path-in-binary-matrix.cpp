/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int directions[8][2] = {
            {-1, -1}, // Top-left
            {-1, 0},  // Top
            {-1, 1},  // Top-right
            {0, -1},  // Left
            {0, 1},   // Right
            {1, -1},  // Bottom-left
            {1, 0},   // Bottom
            {1, 1}    // Bottom-right
        };
        vector<vector<int>> res(n, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minpq;
        if (grid[0][0] == 0)
        {
            minpq.push({1, 0, 0});
            res[0][0] = 1;
        }

        while (!minpq.empty())
        {
            int i = minpq.top()[1], j = minpq.top()[2], weight = minpq.top()[0];
            minpq.pop();

            for (int d = 0; d < 8; d++)
            {
                int newI = i + directions[d][0];
                int newJ = j + directions[d][1];
                if (newI >= 0 && newI < n && newJ >= 0 && newJ < n && grid[newI][newJ] == 0 && weight + 1 < res[newI][newJ])
                {
                    res[newI][newJ] = weight + 1;
                    minpq.push({weight + 1, newI, newJ});
                }
            }
        }
        if (res[n - 1][n - 1] == INT_MAX)
            return -1;
        return res[n - 1][n - 1];
    }
};
// @lc code=end
