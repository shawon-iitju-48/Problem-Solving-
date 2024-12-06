/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    void doadjzero(int i, int j, vector<vector<char>> &grid)
    {
        if (i - 1 >= 0 and grid[i - 1][j] == '1')
        {
            grid[i - 1][j] = '0';
            doadjzero(i - 1, j, grid);
        }
        if (i + 1 < grid.size() and grid[i + 1][j] == '1')
        {
            grid[i + 1][j] = '0';
            doadjzero(i + 1, j, grid);
        }
        if (j - 1 >= 0 and grid[i][j - 1] == '1')
        {
            grid[i][j - 1] = '0';
            doadjzero(i, j - 1, grid);
        }
        if (j + 1 < grid[i].size() and grid[i][j + 1] == '1')
        {
            grid[i][j + 1] = '0';
            doadjzero(i, j + 1, grid);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    doadjzero(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
