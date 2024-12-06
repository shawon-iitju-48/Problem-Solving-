/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int koto = matrix[0].size() - 1;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = koto; j >= 0; j--)
            {
                if (matrix[i][j] == target)
                    return true;
                else if (matrix[i][j] > target)
                    koto = j - 1;
                else
                    break;
            }
        }
        return false;
    }
};
// @lc code=end
