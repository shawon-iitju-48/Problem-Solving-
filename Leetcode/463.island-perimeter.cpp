/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int row = 0, col = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    if (j == 0)
                        row++;
                    else if (grid[i][j - 1] == 0)
                        row++;
                }
            }
        }

        for (int i = 0; i < grid[0].size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                // j=row, i=col
                if (grid[j][i] == 1)
                {
                    if (j == 0)
                        col++;
                    else if (grid[j - 1][i] == 0)
                        col++;
                }
            }
        }
        return row * 2 + col * 2;
    }
};
// @lc code=end
