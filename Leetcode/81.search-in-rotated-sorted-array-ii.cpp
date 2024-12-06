/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int flag = 0;
    void binaryshawon(int f, int l, vector<int> &nums, int &target)
    {
        int mid = f + (l - f) / 2;
        if (f == mid)
        {
            if (binary_search(nums.begin(), nums.begin() + l, target) or binary_search(nums.begin() + l, nums.end(), target))
                flag = 1;
            return;
        }
        if (nums[f] == nums[mid] and nums[mid] == nums[l])
        {
            binaryshawon(f, mid, nums, target);
            binaryshawon(mid, l, nums, target);
        }
        else if (nums[f] <= nums[mid])
            binaryshawon(mid, l, nums, target);
        else
            binaryshawon(f, mid, nums, target);
    }
    bool search(vector<int> &nums, int target)
    {
        binaryshawon(0, nums.size() - 1, nums, target);
        return flag;
    }
};
// @lc code=end
