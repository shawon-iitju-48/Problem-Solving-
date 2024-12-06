/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution
{
public:
    int dp[101][101][101];
    const int MOD = 1e9 + 7;
    int solve(int i, int p, int member, int &n, int &minProfit, vector<int> &group, vector<int> &profit)
    {
        if (i >= group.size())
        {
            if (p == minProfit)
                return 1;
            return 0;
        }
        if (dp[i][p][member] != -1)
            return dp[i][p][member];

        int skip = solve(i + 1, p, member, n, minProfit, group, profit), take = 0;
        if (group[i] + member <= n)
            take = solve(i + 1, min(minProfit, profit[i] + p), member + group[i], n, minProfit, group, profit);

        return dp[i][p][member] = (skip + take) % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, minProfit, group, profit);
    }
};
// @lc code=end
