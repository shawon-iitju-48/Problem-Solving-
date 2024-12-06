/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        unordered_map<long, unordered_map<long, long>> dp;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                long d = (long)nums[i] - (long)nums[j];
                dp[i][d] += 1;
                if (dp.count(j) and dp[j].count(d))
                {
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};
// @lc code=end
