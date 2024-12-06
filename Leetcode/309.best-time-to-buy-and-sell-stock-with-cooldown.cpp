/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution
{
public:
    int buyandsell(int i, int flag, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
            return 0;

        if (dp[flag][i] != -1)
            return dp[flag][i];

        if (flag == 0)
        {
            int left = buyandsell(i + 1, 1, prices, dp) - prices[i];
            int right = buyandsell(i + 1, 0, prices, dp);
            return dp[flag][i] = max(left, right);
        }
        else
        {
            int left = buyandsell(i + 2, 0, prices, dp) + prices[i];
            int right = buyandsell(i + 1, 1, prices, dp);
            return dp[flag][i] = max(left, right);
        }
    }
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(2, vector<int>(prices.size() + 1, -1));
        return buyandsell(0, 0, prices, dp);
    }
};
// @lc code=end
