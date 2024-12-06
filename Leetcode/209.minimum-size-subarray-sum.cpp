/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, j = 0, n = nums.size(), sum = 0, mn = INT_MAX;
        while (i < n and j < n)
        {
            if (sum <= target)
            {
                sum += nums[j];
                j++;
            }
            else if (sum > target)
            {
                sum = sum - nums[i];
                i++;
            }
            if (sum >= target)
                mn = min(mn, j - i);
        }
        while (i < n)
        {
            sum = sum - nums[i];
            i++;
            if (sum >= target)
                mn = min(mn, j - i);
        }
        if (mn == INT_MAX)
            return 0;
        return mn;
    }
};
// @lc code=end
