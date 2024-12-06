/*
 * @lc app=leetcode id=2328 lang=cpp
 *
 * [2328] Number of Increasing Paths in a Grid
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<pair<int, int>>> memo;

    pair<int, int> dfs(int r, int c, vector<vector<int>> &grid)
    {
        if (memo[r][c].first != -1)
            return memo[r][c];

        int sum = 0, ans = 0;
        for (const auto &dir : directions)
        {
            int newR = r + dir[0];
            int newC = c + dir[1];

            if (newR >= 0 && newR < grid.size() && newC >= 0 && newC < grid[0].size() && grid[newR][newC] > grid[r][c])
            {
                auto temp = dfs(newR, newC, grid);
                sum = sum + temp.first;
                ans = ans + temp.second;
            }
        }
        memo[r][c] = {sum + 1, ans + sum + 1};
        return memo[r][c];
    }

    int countPaths(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        memo.assign(m, vector<pair<int, int>>(n, {-1, -1}));
        int result = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (memo[i][j].first == -1)
                    result = result + dfs(i, j, grid).second;
            }
        }
        return result;
    }
};
// @lc code=end
