/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int dp[50][50][11];
    int apple[55][55], m, n;

    int solve(int row_start, int col_start, int k)
    {
        if (apple[row_start][col_start] < k)
            return 0;

        if (k == 1)
            return (apple[row_start][col_start] >= 1) ? 1 : 0;

        if (dp[row_start][col_start][k] != -1)
            return dp[row_start][col_start][k];

        int ways = 0;
        for (int i = row_start + 1; i < m; i++)
        {
            if (apple[row_start][col_start] - apple[i][col_start] > 0 and apple[i][col_start] >= k - 1)
                ways = (ways + solve(i, col_start, k - 1)) % MOD;
        }

        for (int i = col_start + 1; i < n; i++)
        {
            if (apple[row_start][col_start] - apple[row_start][i] > 0 and apple[row_start][i] >= k - 1)
                ways = (ways + solve(row_start, i, k - 1)) % MOD;
        }

        return dp[row_start][col_start][k] = ways % MOD;
    }
    int ways(vector<string> &pizza, int k)
    {
        memset(dp, -1, sizeof(dp));

        m = pizza.size(), n = pizza[0].size();

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                apple[i][j] = apple[i + 1][j] + apple[i][j + 1] - apple[i + 1][j + 1];
                if (pizza[i][j] == 'A')
                    apple[i][j]++;
            }
        }

        return solve(0, 0, k);
    }
};
// @lc code=end
