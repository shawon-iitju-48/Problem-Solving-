/*
 * @lc app=leetcode id=2742 lang=cpp
 *
 * [2742] Painting the Walls
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, unordered_map<int, int>>dp;
    int solve(int i, int n, vector<int> &cost, vector<int> &time)
    {
        if (n <= 0)
            return 0;

        if (i >= cost.size())
            return 1e9;
        
        if(dp[i].count(n))
        return dp[i][n];

        int skip = solve(i + 1, n, cost, time);
        int take = cost[i] + solve(i + 1, n - 1 - time[i], cost, time);

        return dp[i][n]=min(skip, take);
    }
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        return solve(0, cost.size(), cost, time);
    }
};
// @lc code=end
