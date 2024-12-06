/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
class Solution
{
public:
    int rodcutting(int cstart, int cend, int start, int end, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (cstart > cend)
            return 0;
        if (dp[cstart][cend] != -1)
            return dp[cstart][cend];

        int mn = INT_MAX;
        for (int i = cstart; i <= cend; i++)
            mn = min(mn, end - start + rodcutting(cstart, i - 1, start, cuts[i], cuts, dp) + rodcutting(i + 1, cend, cuts[i], end, cuts, dp));

        if (mn == INT_MAX)
            return dp[cstart][cend] = 0;
        else
            return dp[cstart][cend] = mn;
    }
    int minCost(int n, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size() + 1, vector<int>(cuts.size() + 1, -1));
        return rodcutting(0, cuts.size() - 1, 0, n, cuts, dp);
    }
};
// @lc code=end
