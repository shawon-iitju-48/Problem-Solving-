/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> dp;
    int solve(int i, int diff, vector<int> &rods)
    {
        if (i >= rods.size())
            return (diff == 0) ? 0 : INT_MIN;

        if (dp[i].count(diff))
            return dp[i][diff];

        int mx = solve(i + 1, diff, rods);
        mx = max(mx, rods[i] + solve(i + 1, diff - rods[i], rods));
        mx = max(mx, solve(i + 1, diff + rods[i], rods));

        return dp[i][diff] = mx;
    }
    int tallestBillboard(vector<int> &rods)
    {
        return solve(0, 0, rods);
    }
};
// @lc code=end
