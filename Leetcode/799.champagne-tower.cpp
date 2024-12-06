/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> pascal(100, vector<double>(100, 0.0));
        pascal[0][0] = poured;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (pascal[i][j] > 1.00)
                {
                    double x = (pascal[i][j] - 1.00) / 2.00;
                    pascal[i][j] = 1.00;
                    if (i + 1 < 100)
                    {
                        pascal[i + 1][j] += x;
                        if (j + 1 < 100)
                            pascal[i + 1][j + 1] += x;
                    }
                }
            }
        }
        return pascal[query_row][query_glass];
    }
};
// @lc code=end
