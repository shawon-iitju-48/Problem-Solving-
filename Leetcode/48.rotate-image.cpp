/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int a = 0, b = 0, n = matrix.size();
        while (b < n)
        {
            int aa = a, bb = b;
            while (aa >= bb)
            {
                swap(matrix[aa][bb], matrix[bb][aa]);
                aa--, bb++;
            }
            a++;
            if (a == n)
                a = n - 1, b++;
        }
        for (int i = 0; i < n; i++)
        {
            int start = 0, end = n - 1;
            while (start <= end)
            {
                swap(matrix[i][start], matrix[i][end]);
                start++, end--;
            }
        }
    }
};
// @lc code=end
