/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
class Solution
{
public:
    double dp[301][301];
    double solve(int a, int b)
    {
        if (a <= 0 and b <= 0)
            return 0.5;

        if (a <= 0)
            return 1.0;

        if (b <= 0)
            return 0.0;

        if (dp[a][b] != -1.0)
            return dp[a][b];

        double prob = solve(a - 4, b);
        prob += solve(a - 3, b - 1);
        prob += solve(a - 2, b - 2);
        prob += solve(a - 1, b - 3);

        return dp[a][b] = prob * 0.25;
    }
    double soupServings(int n)
    {
        if (n > 5000)
            return 1.0;

        n = (n + 24) / 25;

        for (int i = 0; i <= 300; i++)
            for (int j = 0; j <= 300; j++)
                dp[i][j] = -1.0;

        return solve(n, n);
    }
};
// @lc code=end
