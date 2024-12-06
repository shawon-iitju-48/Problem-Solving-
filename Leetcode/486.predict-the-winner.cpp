/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution
{
public:
    int solve(int start, int end, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (start == end)
            return nums[start];

        if (dp[start][end] != -1)
            return dp[start][end];

        int mx = nums[start] - solve(start + 1, end, nums, dp);
        mx = max(mx, nums[end] - solve(start, end - 1, nums, dp));

        return dp[start][end] = mx;
    }
    bool predictTheWinner(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        if (solve(0, nums.size() - 1, nums, dp) >= 0)
            return true;
        return false;
    }
};
// @lc code=end
