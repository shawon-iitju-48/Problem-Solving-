/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int f = 0, l = nums.size() - 1, mid;
        while (f <= l)
        {
            mid = (f + l) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] < nums[l])
            {
                if (nums[mid] < target and target <= nums[l])
                    f = mid + 1;
                else
                    l = mid - 1;
            }
            else
            {
                if (nums[f] <= target and target < nums[mid])
                    l = mid - 1;
                else
                    f = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
//find the ascending order and elimate the range if target is not in the ascending range
