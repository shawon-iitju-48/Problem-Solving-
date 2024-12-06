/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:
    int doadjzero(int i, int j, vector<vector<int>> &grid)
    {
        int cnt = 0;

        if (i - 1 >= 0 and grid[i - 1][j] == 1)
        {
            grid[i - 1][j] = 0;
            cnt = cnt + 1 + doadjzero(i - 1, j, grid);
        }
        if (i + 1 < grid.size() and grid[i + 1][j] == 1)
        {
            grid[i + 1][j] = 0;
            cnt = cnt + 1 + doadjzero(i + 1, j, grid);
        }
        if (j - 1 >= 0 and grid[i][j - 1] == 1)
        {
            grid[i][j - 1] = 0;
            cnt = cnt + 1 + doadjzero(i, j - 1, grid);
        }
        if (j + 1 < grid[i].size() and grid[i][j + 1] == 1)
        {
            grid[i][j + 1] = 0;
            cnt = cnt + 1 + doadjzero(i, j + 1, grid);
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int mx = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    mx = max(mx, 1 + doadjzero(i, j, grid));
                }
            }
        }
        return mx;
    }
};
// @lc code=end
