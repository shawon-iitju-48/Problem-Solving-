/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution
{
public:
    bool doadjzero(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        if (i < 0 or j < 0 or i >= grid2.size() or j >= grid2[0].size() or grid2[i][j] == 0)
            return true;

        if (grid1[i][j] == 0)
            return false;

        grid2[i][j] = 0;

        bool isSubIsland = true;
        isSubIsland &= doadjzero(i, j - 1, grid1, grid2);
        isSubIsland &= doadjzero(i - 1, j, grid1, grid2);
        isSubIsland &= doadjzero(i, j + 1, grid1, grid2);
        isSubIsland &= doadjzero(i + 1, j, grid1, grid2);

        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid2.size(), n = grid2[0].size(), cnt = 0, ti, tj;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1 and doadjzero(i, j, grid1, grid2))
                    cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end
