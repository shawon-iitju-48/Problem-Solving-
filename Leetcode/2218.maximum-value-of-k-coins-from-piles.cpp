/*
 * @lc app=leetcode id=2218 lang=cpp
 *
 * [2218] Maximum Value of K Coins From Piles
 */

// @lc code=start
class Solution
{
public:
    int solve(int idx, int k, vector<vector<int>> &piles, vector<vector<int>> &dp)
    {
        if (idx >= piles.size() or k == 0)
            return 0;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int mx = 0, sum = 0;
        mx = max(mx, solve(idx + 1, k, piles, dp));
        for (int i = 0; i < piles[idx].size() and i < k; i++)
        {
            sum += piles[idx][i];
            mx = max(mx, sum + solve(idx + 1, k - i - 1, piles, dp));
        }
        return dp[idx][k] = mx;
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        vector<vector<int>> dp(piles.size(), vector<int>(k + 1, -1));
        return solve(0, k, piles, dp);
    }
};
// @lc code=end
