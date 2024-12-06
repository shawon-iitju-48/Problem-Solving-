/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
    bool checksum(int i, int current, int sum, vector<int> &nums, vector<int> &dp)
    {
        if (i == nums.size() or current > sum)
            return 0;

        if (current == sum)
            return 1;

        if (dp[current] != -1)
            return dp[current];

        if (checksum(i + 1, current, sum, nums, dp) == 1)
            return dp[current] = 1;
        if (checksum(i + 1, current + nums[i], sum - nums[i], nums, dp) == 1)
            return dp[current] = 1;

        return dp[current] = 0;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        vector<int> dp(sum + 2, -1);
        return checksum(0, 0, sum, nums, dp);
    }
};
// @lc code=end
