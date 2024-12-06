/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 */

// @lc code=start
class Solution
{
public:
    int n, MOD = 1e9 + 7;
    int dp[100005][4][2];
    int solve(int count, int l, int a)
    {
        if (count == n)
            return 1;

        if (dp[count][l][a] != -1)
            return dp[count][l][a];

        int cnt = 0;
        if (l < 2)
            cnt = (cnt + solve(count + 1, l + 1, a)) % MOD;

        cnt = (cnt + solve(count + 1, 0, a)) % MOD;

        if (a == 0)
            cnt = (cnt + solve(count + 1, 0, 1)) % MOD;

        return dp[count][l][a] = cnt;
    }
    int checkRecord(int nn)
    {
        n = nn;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};
// @lc code=end
