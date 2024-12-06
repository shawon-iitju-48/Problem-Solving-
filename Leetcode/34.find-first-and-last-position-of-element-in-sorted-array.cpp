/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (binary_search(nums.begin(), nums.end(), target))
        {
            auto it = lower_bound(nums.begin(), nums.end(), target);
            auto itt = upper_bound(nums.begin(), nums.end(), target);
            int lb = it - nums.begin(), rb = itt - nums.begin() - 1;
            return {lb, rb};
        }
        return {-1, -1};
    }
};
// @lc code=end
