/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        unordered_map<int, unordered_map<int, int>> dp;
        int mx = INT_MIN;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                dp[i][diff] = max(2, 1 + dp[j][diff]);
                mx = max(mx, dp[i][diff]);
            }
        }
        return mx;
    }
};
// @lc code=end
