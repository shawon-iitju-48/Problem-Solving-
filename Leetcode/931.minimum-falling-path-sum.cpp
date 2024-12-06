/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        for (int i = matrix.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                int one = INT_MAX, two = INT_MAX, three = INT_MAX;
                if (j - 1 >= 0)
                    one = matrix[i + 1][j - 1];
                two = matrix[i + 1][j];
                if (j + 1 < matrix.size())
                    three = matrix[i + 1][j + 1];
                matrix[i][j] += min({one, two, three});
            }
        }
        int mn = INT_MAX;
        for (int i = 0; i < matrix.size(); i++)
            mn = min(mn, matrix[0][i]);
        return mn;
    }
};
// @lc code=end
