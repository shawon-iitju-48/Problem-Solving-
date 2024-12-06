/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int f = 0, l = nums.size() - 1, mid;
        while (f < l)
        {
            mid = (l + f) / 2;
            if (nums[mid] > nums[f])
                f = mid;
            else
                l = mid;
        }
        if (nums[0] < nums[nums.size() - 1])
            return nums[0];
        else
            return nums[mid + 1];
    }
};
// @lc code=end
