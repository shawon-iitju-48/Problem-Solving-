/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution
{
public:
    int coinchange(int i, int sum, int &amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (sum == amount)
            return 1;

        if (i >= coins.size() or sum > amount)
            return 0;
        if (dp[sum][i] != -1)
            return dp[sum][i];

        int take = coinchange(i, sum + coins[i], amount, coins, dp);
        int skip = coinchange(i + 1, sum, amount, coins, dp);
        return dp[sum][i] = take + skip;
    }
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, -1));
        return coinchange(0, 0, amount, coins, dp);
    }
};
// @lc code=end
