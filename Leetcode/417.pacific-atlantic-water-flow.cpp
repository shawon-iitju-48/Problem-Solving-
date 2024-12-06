/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, int j, int prev, vector<vector<int>> &heights, vector<vector<int>> &ocean)
    {
        if (i < 0 or j < 0 or i >= heights.size() or j >= heights[0].size() or ocean[i][j] == 1 or heights[i][j] < prev)
            return;

        ocean[i][j] = 1;
        dfs(i, j - 1, heights[i][j], heights, ocean);
        dfs(i - 1, j, heights[i][j], heights, ocean);
        dfs(i, j + 1, heights[i][j], heights, ocean);
        dfs(i + 1, j, heights[i][j], heights, ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int row = heights.size(), col = heights[0].size();
        vector<vector<int>> pacific(row, vector<int>(col, 0)), atlantic(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            dfs(i, 0, INT_MIN, heights, pacific);
            dfs(i, col - 1, INT_MIN, heights, atlantic);
        }
        for (int i = 0; i < col; i++)
        {
            dfs(0, i, INT_MIN, heights, pacific);
            dfs(row - 1, i, INT_MIN, heights, atlantic);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (pacific[i][j] == 1 and atlantic[i][j] == 1)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
// @lc code=end
