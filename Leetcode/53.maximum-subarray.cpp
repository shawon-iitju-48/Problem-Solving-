/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int best = nums[0], sum = 0;
        for (int k = 0; k < nums.size(); k++)
        {
            sum = max(nums[k], sum + nums[k]);
            best = max(best, sum);
        }
        return best;
    }
};
// @lc code=end
