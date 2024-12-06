/*
 * @lc app=leetcode id=2812 lang=cpp
 *
 * [2812] Find the Safest Path in a Grid
 */

// @lc code=start
class Solution
{
public:
    int dijkstra(vector<vector<int>> &cost)
    {
        int n = cost.size();
        vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<vector<int>> res(n, vector<int>(n, INT_MIN));
        res[0][0] = cost[0][0];

        priority_queue<vector<int>> q;
        q.push({cost[0][0], 0, 0});

        while (!q.empty())
        {
            int price = q.top()[0], i = q.top()[1], j = q.top()[2];
            q.pop();
            if (i == n - 1 and j == n - 1)
                return price;

            for (auto &d : directions)
            {
                int newI = i + d.first, newJ = j + d.second;
                if (newI >= 0 and newJ >= 0 and newI < n and newJ < n and min(price, cost[newI][newJ]) > res[newI][newJ])
                {
                    res[newI][newJ] = min(price, cost[newI][newJ]);
                    q.push({res[newI][newJ], newI, newJ});
                }
            }
        }
        return -1;
    }
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    cost[i][j] = 0;
                    q.push({0, i, j});
                }
            }
        }
        vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!q.empty())
        {
            int step = q.front()[0], i = q.front()[1], j = q.front()[2];
            q.pop();

            for (auto &d : directions)
            {
                int newI = i + d.first, newJ = j + d.second;
                if (newI >= 0 and newJ >= 0 and newI < n and newJ < n and step + 1 < cost[newI][newJ])
                {
                    cost[newI][newJ] = step + 1;
                    q.push({step + 1, newI, newJ});
                }
            }
        }
        return dijkstra(cost);
    }
};
// @lc code=end
