/*
 * @lc app=leetcode id=1992 lang=cpp
 *
 * [1992] Find All Groups of Farmland
 */

// @lc code=start
class Solution
{
public:
    int ti, tj;
    void dfs(int i, int j, vector<vector<int>> &land)
    {
        if (i < 0 or j < 0 or i >= land.size() or j >= land[0].size() or land[i][j] == 0)
            return;
        land[i][j] = 0;
        ti = max(ti, i), tj = max(tj, j);
        dfs(i, j - 1, land);
        dfs(i - 1, j, land);
        dfs(i, j + 1, land);
        dfs(i + 1, j, land);
    }
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < land.size(); i++)
        {
            for (int j = 0; j < land[i].size(); j++)
            {
                if (land[i][j] == 1)
                {
                    ti = -1, tj = -1;
                    dfs(i, j, land);
                    ans.push_back({i, j, ti, tj});
                }
            }
        }
        return ans;
    }
};
// @lc code=end
