/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class Solution
{
public:
    long long solve(int idx, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (idx >= questions.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        return max(questions[idx][0] + solve(idx + questions[idx][1] + 1, questions, dp), solve(idx + 1, questions, dp));
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<long long> dp(questions.size(), -1);
        return solve(0, questions, dp);
    }
};
// @lc code=end
