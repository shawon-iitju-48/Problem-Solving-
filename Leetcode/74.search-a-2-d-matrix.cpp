/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix[0].size(), first = 0, last = (matrix.size() * n) - 1, mid;
        while (first <= last)
        {
            mid = (first + last) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                first = mid + 1;
            else
                last = mid - 1;
        }
        return false;
    }
};
// @lc code=end
