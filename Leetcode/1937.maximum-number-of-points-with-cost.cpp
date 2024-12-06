/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        vector<long long> left(n, 0), right(n, 0);

        for (int i = 0; i < n; i++)
            dp[0][i] = (long long)points[0][i];

        for (int i = 1; i < m; i++)
        {
            left[0] = dp[i - 1][0];
            for (int j = 1; j < n; j++)
                left[j] = max(dp[i - 1][j], left[j - 1] - 1);

            right[n - 1] = dp[i - 1][n - 1];
            for (int j = n - 2; j >= 0; j--)
                right[j] = max(dp[i - 1][j], right[j + 1] - 1);

            for (int j = 0; j < n; j++)
                dp[i][j] = (long long)points[i][j] + max(left[j], right[j]);
        }

        long long mx = dp[m - 1][0];
        for (int i = 1; i < n; i++)
            mx = max(mx, dp[m - 1][i]);

        return mx;
    }
};
// @lc code=end
