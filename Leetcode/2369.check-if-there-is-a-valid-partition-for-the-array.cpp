/*
 * @lc app=leetcode id=2369 lang=cpp
 *
 * [2369] Check if There is a Valid Partition For The Array
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, bool> dp;
    bool solve(int idx, vector<int> &nums)
    {
        if (idx >= nums.size())
            return true;

        if (dp.count(idx))
            return dp[idx];

        if (idx + 1 < nums.size() and nums[idx] == nums[idx + 1] and solve(idx + 2, nums))
            return dp[idx] = true;

        if (idx + 2 < nums.size())
        {
            if (nums[idx] == nums[idx + 1] and nums[idx + 1] == nums[idx + 2] and solve(idx + 3, nums))
                return dp[idx] = true;

            if (nums[idx + 1] - nums[idx] == 1 and nums[idx + 2] - nums[idx + 1] == 1 and solve(idx + 3, nums))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool validPartition(vector<int> &nums)
    {
        return solve(0, nums);
    }
};
// @lc code=end
