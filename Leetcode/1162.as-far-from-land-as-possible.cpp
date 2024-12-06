/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution
{
public:
    int mx = -1;
    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid, queue<vector<int>> &q, vector<pair<int, int>> &directions, vector<vector<int>> &res)
    {
        for (auto &d : directions)
        {
            int new_i = i + d.first, new_j = j + d.second;
            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size() && !visited[new_i][new_j])
            {
                visited[new_i][new_j] = true;
                if (grid[new_i][new_j] == 0)
                {
                    q.push({new_i, new_j, 1});
                    res[new_i][new_j] = 1;
                    mx = max(mx, res[new_i][new_j]);
                }
                else
                    dfs(new_i, new_j, visited, grid, q, directions, res);
            }
        }
    }

    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<vector<int>> q;
        vector<vector<int>> res(n, vector<int>(n, INT_MAX));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    visited[i][j] = true;
                    dfs(i, j, visited, grid, q, directions, res);
                }
            }
        }

        while (!q.empty())
        {
            int ni = q.front()[0], nj = q.front()[1], step = q.front()[2];
            q.pop();

            for (auto &d : directions)
            {
                int new_i = ni + d.first, new_j = nj + d.second;
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n)
                {
                    if (grid[new_i][new_j] == 0 && step + 1 < res[new_i][new_j])
                    {
                        q.push({new_i, new_j, step + 1});
                        res[new_i][new_j] = step + 1;
                        mx = max(mx, res[new_i][new_j]);
                    }
                }
            }
        }
        return mx;
    }
};
// @lc code=end
