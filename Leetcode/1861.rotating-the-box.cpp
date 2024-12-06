/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = m - 1; i >= 0; i--)
        {
            int row = n - 1, col = m - 1 - i;
            for (int j = n - 1; j >= 0; j--)
            {
                if (boxGrid[i][j] == '.')
                    continue;

                if (boxGrid[i][j] == '*')
                {
                    ans[j][col] = '*';
                    row = j - 1;
                }
                else
                {
                    ans[row][col] = '#';
                    row--;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
