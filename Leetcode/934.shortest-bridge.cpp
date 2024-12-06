/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid, queue<vector<int>> &q)
    {
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int d = 0; d < 4; ++d)
        {
            int new_i = i + directions[d][0];
            int new_j = j + directions[d][1];

            if (new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size())
            {
                if (grid[new_i][new_j] == 0 && !visited[new_i][new_j])
                {
                    q.push({new_i, new_j, 1});
                    visited[new_i][new_j] = true;
                }
                else if (grid[new_i][new_j] == 1 && !visited[new_i][new_j])
                {
                    visited[new_i][new_j] = true;
                    dfs(new_i, new_j, visited, grid, q);
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<vector<int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    visited[i][j] = true;
                    dfs(i, j, visited, grid, q);
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            int ni = q.front()[0], nj = q.front()[1], step = q.front()[2];
            q.pop();

            for (int d = 0; d < 4; ++d)
            {
                int new_i = ni + directions[d][0];
                int new_j = nj + directions[d][1];

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n)
                {
                    if (grid[new_i][new_j] == 1 && !visited[new_i][new_j])
                        return step;

                    else if (grid[new_i][new_j] == 0 && !visited[new_i][new_j])
                    {
                        visited[new_i][new_j] = true;
                        q.push({new_i, new_j, step + 1});
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
