/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Solution
{
public:
    int solveit(int index, vector<int> &jobDifficulty, int d, vector<vector<int>> &dp)
    {
        if ((index < jobDifficulty.size() and d <= 0) or (index >= jobDifficulty.size() and d > 0))
            return 1e8;

        if (index == jobDifficulty.size() and d == 0)
            return 0;

        if (dp[index][d] != -1)
            return dp[index][d];

        int mxVal = INT_MIN, mn = 1e8;
        for (int i = index; i < jobDifficulty.size(); i++)
        {
            mxVal = max(mxVal, jobDifficulty[i]);
            mn = min(mn, mxVal + solveit(i + 1, jobDifficulty, d - 1, dp));
        }
        return dp[index][d] = mn;
    }
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        if (d > jobDifficulty.size())
            return -1;
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));
        return solveit(0, jobDifficulty, d, dp);
    }
};
// @lc code=end
