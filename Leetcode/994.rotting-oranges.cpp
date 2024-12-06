/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution
{
public:
    int solve(queue<pair<int, int>> &q, vector<vector<int>> &grid)
    {
        if (q.empty())
            return 0;
        int cnt = q.size(), flag = 0;
        while (cnt--)
        {
            int i = q.front().first, j = q.front().second;
            if (i - 1 >= 0 and grid[i - 1][j] == 1)
            {
                grid[i - 1][j] = 2;
                q.push({i - 1, j});
                flag = 1;
            }
            if (j - 1 >= 0 and grid[i][j - 1] == 1)
            {
                grid[i][j - 1] = 2;
                q.push({i, j - 1});
                flag = 1;
            }
            if (i + 1 < grid.size() and grid[i + 1][j] == 1)
            {
                grid[i + 1][j] = 2;
                q.push({i + 1, j});
                flag = 1;
            }
            if (j + 1 < grid[0].size() and grid[i][j + 1] == 1)
            {
                grid[i][j + 1] = 2;
                q.push({i, j + 1});
                flag = 1;
            }
            q.pop();
        }
        return flag + solve(q, grid);
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 2)
                    q.push({i, j});
        int result = solve(q, grid);
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1)
                    return -1;
        return result;
    }
};
// @lc code=end
