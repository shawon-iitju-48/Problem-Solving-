/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int mstart = m - 1, nstart = n - 1, i = m + n - 1;
        while (nstart >= 0)
        {
            if (mstart >= 0 and nums1[mstart] > nums2[nstart])
                nums1[i--] = nums1[mstart--];
            else
                nums1[i--] = nums2[nstart--];
        }
    }
};
// @lc code=end
