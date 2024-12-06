/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */

// @lc code=start
class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        vector<vector<long long>> dp(n, vector<long long>(n + 2, INT_MIN));
        sort(begin(satisfaction), end(satisfaction));
        for (int i = 0; i < n; i++)
            dp[i][0] = 0;

        dp[0][1] = satisfaction[0];

        for (int i = 1; i < n; i++)
        {
            for (int time = 1; time <= n; time++)
            {
                long long skip = dp[i - 1][time];
                long long take = (long long)satisfaction[i] * time + dp[i - 1][time - 1];
                dp[i][time] = max(skip, take);
            }
        }
        long long mx = INT_MIN;
        for (int time = 1; time <= n; time++)
            mx = max(mx, dp[n - 1][time]);
        return mx;
    }
};
// @lc code=end
