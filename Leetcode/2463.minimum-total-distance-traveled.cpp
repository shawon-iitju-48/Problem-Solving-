/*
 * @lc app=leetcode id=2463 lang=cpp
 *
 * [2463] Minimum Total Distance Traveled
 */

// @lc code=start
class Solution
{
public:
    long long solve(int r, int f, vector<int> &robot, vector<int> &factory, vector<vector<long long>> &dp)
    {
        if (r >= robot.size())
            return 0;

        if (f >= factory.size())
            return 1e12;

        if (dp[r][f] != -1)
            return dp[r][f];

        long long repair = abs(factory[f] - robot[r]) + solve(r + 1, f + 1, robot, factory, dp);
        long long not_repair = solve(r, f + 1, robot, factory, dp);

        return dp[r][f] = min(repair, not_repair);
    }
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));

        vector<int> factory_expanded;
        for (int i = 0; i < factory.size(); i++)
        {
            for (int j = 0; j < factory[i][1]; j++)
                factory_expanded.push_back(factory[i][0]);
        }
        vector<vector<long long>> dp(robot.size(), vector<long long>(factory_expanded.size(), -1));
        return solve(0, 0, robot, factory_expanded, dp);
    }
};
// @lc code=end
