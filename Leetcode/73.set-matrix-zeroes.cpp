/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = 0, col = 0;
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[j][0] == 0)
            {
                col = 1;
                break;
            }
        }

        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0)
            {
                row = 1;
                break;
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][0] == 0 or matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (col == 1)
            for (int j = 0; j < matrix.size(); j++)
                matrix[j][0] = 0;
        if (row == 1)
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
    }
};
// @lc code=end
