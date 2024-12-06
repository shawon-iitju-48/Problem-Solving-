/*
 * @lc app=leetcode id=3154 lang=cpp
 *
 * [3154] Find Number of Ways to Reach the K-th Stair
 */

// @lc code=start
class Solution
{
public:
    int target;
    unordered_map<int, unordered_map<int, int>> dp;
    int solve(int current, int jump)
    {
        if (current > target + 1)
            return 0;

        if (dp[current].count(jump))
            return dp[current][jump];

        int cnt = 0;
        if (target == current)
            cnt++;

        if (current - 1 == target)
            cnt++;

        if (current > 0)
            cnt += solve((current - 1) + (1 << jump), jump + 1);

        cnt = cnt + solve(current + (1 << jump), jump + 1);

        return dp[current][jump] = cnt;
    }
    int waysToReachStair(int k)
    {
        target = k;
        return solve(1, 0);
    }
};
// @lc code=end
