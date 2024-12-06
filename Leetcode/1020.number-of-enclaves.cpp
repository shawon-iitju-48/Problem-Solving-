/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or visited[i][j] == false or grid[i][j] == 0)
            return;
        visited[i][j] = false;
        dfs(i, j - 1, grid, visited);
        dfs(i - 1, j, grid, visited);
        dfs(i, j + 1, grid, visited);
        dfs(i + 1, j, grid, visited);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), true));
        for (int i = 0; i < grid.size(); i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, visited);
            if (grid[i][grid[0].size() - 1] == 1)
                dfs(i, grid[0].size() - 1, grid, visited);
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            if (grid[0][i] == 1)
                dfs(0, i, grid, visited);
            if (grid[grid.size() - 1][i] == 1)
                dfs(grid.size() - 1, i, grid, visited);
        }
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (visited[i][j] and grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end
