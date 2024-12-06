/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution
{
public:
    int solve(int i, int flag, vector<int> &prices, int &fee, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
            return 0;

        if (dp[i][flag] != -1)
            return dp[i][flag];

        int profit = INT_MIN;
        if (flag == 0)
        {
            profit = max(profit, solve(i + 1, flag, prices, fee, dp));
            profit = max(profit, solve(i + 1, 1 - flag, prices, fee, dp) - prices[i] - fee);
        }
        else
        {
            profit = max(profit, solve(i + 1, flag, prices, fee, dp));
            profit = max(profit, solve(i + 1, 1 - flag, prices, fee, dp) + prices[i]);
        }
        return dp[i][flag] = profit;
    }
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(0, 0, prices, fee, dp);
    }
};
// @lc code=end
