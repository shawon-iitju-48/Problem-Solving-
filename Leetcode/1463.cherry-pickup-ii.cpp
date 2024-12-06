class Solution
{
public:
    int solve(int r, int c1, int c2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        int m = grid.size(), n = grid[0].size();
        if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)
            return 0;

        if (r == m - 1)
        {
            if (c1 == c2)
                return grid[r][c1];
            else
                return grid[r][c1] + grid[r][c2];
        }

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        int maxCherries = 0;
        for (int d1 = -1; d1 <= 1; ++d1)
        {
            for (int d2 = -1; d2 <= 1; ++d2)
                maxCherries = max(maxCherries, solve(r + 1, c1 + d1, c2 + d2, grid, dp));
        }

        if (c1 == c2)
            dp[r][c1][c2] = grid[r][c1] + maxCherries;
        else
            dp[r][c1][c2] = grid[r][c1] + grid[r][c2] + maxCherries;

        return dp[r][c1][c2];
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, n - 1, grid, dp);
    }
};
