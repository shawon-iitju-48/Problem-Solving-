/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int houserobber(int i, int &sz, vector<int> &dp, vector<int> &nums)
    {
        if (i >= sz)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        dp[i] = max(nums[i] + houserobber(i + 2, sz, dp, nums), houserobber(i + 1, sz, dp, nums));
        return dp[i];
    }
    int rob(vector<int> &nums)
    {
        vector<int> dp1(nums.size() + 1, -1), dp2(nums.size() + 1, -1);

        return max(houserobber(1, n - 1, dp1, nums), houserobber(0, n, dp2, nums));
    }
};
// @lc code=end
