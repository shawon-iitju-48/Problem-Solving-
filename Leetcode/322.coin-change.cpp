/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
public:
    int changecoin(int amount, vector<int> &coins, vector<int> &dp)
    {
        if (amount < 0)
            return INT_MAX;
        if (dp[amount] != -1)
            return dp[amount];
        int mn = INT_MAX, r;
        for (int i = 0; i < coins.size(); i++)
        {
            r = changecoin(amount - coins[i], coins, dp);
            if (r >= 0)
                mn = min(mn, r);
        }
        if (mn != INT_MAX)
            dp[amount] = mn + 1;
        else
            dp[amount] = mn;
        return dp[amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        int result = changecoin(amount, coins, dp);
        if (result == INT_MAX)
            return -1;
        else
            return result;
    }
};
// @lc code=end
