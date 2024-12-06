/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int climbmin(int i, vector<int> &dp, vector<int> &cost)
    {
        if (i >= cost.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        dp[i] = min(cost[i] + climbmin(i + 1, dp, cost), cost[i] + climbmin(i + 2, dp, cost));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 2, -1);
        return min(climbmin(0, dp, cost), climbmin(1, dp, cost));
    }
};
// @lc code=end
