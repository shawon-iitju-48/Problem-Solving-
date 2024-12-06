/*
 * @lc app=leetcode id=1901 lang=cpp
 *
 * [1901] Find a Peak Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int f, l, mid, left, right, top, bottom, m = mat.size(), n = mat[0].size();

        for (int i = 0; i < m; i++)
        {
            f = 0, l = n - 1;
            while (f <= l)
            {
                mid = f + (l - f) / 2;
                left = -1, right = -1, top = -1, bottom = -1;
                if (mid - 1 >= 0)
                    left = mat[i][mid - 1];
                if (mid + 1 < n)
                    right = mat[i][mid + 1];
                if (i - 1 >= 0)
                    top = mat[i - 1][mid];
                if (i + 1 < m)
                    bottom = mat[i + 1][mid];
                if (mat[i][mid] > left and mat[i][mid] > right and mat[i][mid] > top and mat[i][mid] > bottom)
                    return {i, mid};
                if (mat[i][mid] < right)
                    f = mid + 1;
                else
                    l = mid - 1;
            }
            f = 0, l = n - 1;
            while (f <= l)
            {
                mid = f + (l - f) / 2;
                left = -1, right = -1, top = -1, bottom = -1;
                if (mid - 1 >= 0)
                    left = mat[i][mid - 1];
                if (mid + 1 < n)
                    right = mat[i][mid + 1];
                if (i - 1 >= 0)
                    top = mat[i - 1][mid];
                if (i + 1 < m)
                    bottom = mat[i + 1][mid];
                if (mat[i][mid] > left and mat[i][mid] > right and mat[i][mid] > top and mat[i][mid] > bottom)
                    return {i, mid};
                if (mat[i][mid] < left)
                    l = mid - 1;
                else
                    f = mid + 1;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
