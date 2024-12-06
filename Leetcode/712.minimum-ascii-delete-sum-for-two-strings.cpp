/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution
{
public:
    int dp[1000][1000];
    int solve(int i, int j, string &s1, string &s2)
    {
        if (i >= s1.size() or j >= s2.size())
        {
            int sum = 0;
            for (int d = i; d < s1.size(); d++)
                sum += s1[d];

            for (int d = j; d < s2.size(); d++)
                sum += s2[d];

            return sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = solve(i + 1, j + 1, s1, s2);

        return dp[i][j] = min(s1[i] + solve(i + 1, j, s1, s2), s2[j] + solve(i, j + 1, s1, s2));
    }
    int minimumDeleteSum(string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2);
    }
};
// @lc code=end
