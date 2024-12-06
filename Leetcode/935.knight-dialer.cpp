/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
class Solution
{
public:
    const int MOD = 1e9 + 7;
    vector<pair<int, int>> dir = {{2, -1}, {2, 1}, {-2, 1}, {-2, -1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}};

    int solve(int i, int j, int n, vector<vector<vector<int>>> &dp)
    {
        if (n == 0)
            return 1;

        if (dp[i][j][n] != -1)
            return dp[i][j][n];

        int cnt = 0;
        for (int d = 0; d < 8; d++)
        {
            int newI = i + dir[d].first;
            int newJ = j + dir[d].second;

            if (newI >= 0 and newI < 4 and newJ >= 0 and newJ < 3 and !(newI == 3 and (newJ == 0 or newJ == 2)))
                cnt = (cnt + solve(newI, newJ, n - 1, dp)) % MOD;
        }
        return dp[i][j][n] = cnt;
    }

    int knightDialer(int n)
    {
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        int sum = solve(3, 1, n - 1, dp);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                sum = (sum + solve(i, j, n - 1, dp)) % MOD;
        }
        return sum;
    }
};
// @lc code=end
