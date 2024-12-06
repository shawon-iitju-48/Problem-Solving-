/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int houserobber(int i, vector<int> &dp, vector<int> &nums)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        dp[i] = max(nums[i] + houserobber(i + 2, dp, nums), houserobber(i + 1, dp, nums));
        return dp[i];
    }
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);
        return houserobber(0, dp, nums);
    }
};
// @lc code=end
