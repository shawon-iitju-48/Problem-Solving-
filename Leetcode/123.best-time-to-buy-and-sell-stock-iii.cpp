/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution
{
public:
    int solve(int i, int flag, int trx, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (i >= prices.size() or trx == 2)
            return 0;

        if (dp[i][flag][trx] != -1)
            return dp[i][flag][trx];

        int mx = solve(i + 1, flag, trx, prices, dp);
        if (flag == 1)
            mx = max(mx, solve(i + 1, 1 - flag, trx, prices, dp) - prices[i]);
        else
            mx = max(mx, solve(i + 1, 1 - flag, trx + 1, prices, dp) + prices[i]);
            
        return dp[i][flag][trx] = mx;
    }
    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 0, prices, dp);
    }
};
// @lc code=end
