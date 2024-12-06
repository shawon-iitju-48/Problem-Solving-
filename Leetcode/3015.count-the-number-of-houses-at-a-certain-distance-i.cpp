/*
 * @lc app=leetcode id=3015 lang=cpp
 *
 * [3015] Count the Number of Houses at a Certain Distance I
 */

// @lc code=start
class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i <= n; i++)
            dist[i][i] = 0;

        for (int i = 1; i < n; i++)
        {
            dist[i][i + 1] = 1;
            dist[i + 1][i] = 1;
        }
        dist[x][y] = 1;
        dist[y][x] = 1;

        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (dist[i][k] == INT_MAX)
                    continue;
                for (int j = 1; j <= n; j++)
                {
                    if (dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        vector<int> ans(n, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j and dist[i][j] != INT_MAX)
                    ans[dist[i][j] - 1]++;
            }
        }
        return ans;
    }
};
// @lc code=end
