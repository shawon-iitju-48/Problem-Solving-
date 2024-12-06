/*
 * @lc app=leetcode id=2577 lang=cpp
 *
 * [2577] Minimum Time to Visit a Cell In a Grid
 */

// @lc code=start
class Solution
{
public:
    int minimumTime(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});
        dist[0][0] = 0;

        if (grid[0][1] > 1 and grid[1][0] > 1)
            return -1;

        while (!q.empty())
        {
            int currTime = q.top()[0], i = q.top()[1], j = q.top()[2];
            q.pop();

            if (currTime > dist[i][j])
                continue;

            for (int d = 0; d < 4; d++)
            {
                int newI = i + dir[d].first;
                int newJ = j + dir[d].second;

                if (newI >= 0 and newJ >= 0 and newI < m and newJ < n)
                {
                    int newTime = currTime + 1;
                    if (currTime < grid[newI][newJ])
                    {
                        newTime = grid[newI][newJ];
                        if ((grid[newI][newj] - currTime) % 2 == 0)
                            newTime++;
                    }

                    if (newTime < dist[newI][newJ])
                    {
                        dist[newI][newJ] = newTime;
                        q.push({newTime, newI, newJ});
                    }
                }
            }
        }
        return dist[m - 1][n - 1] == INT_MAX ? -1 : dist[m - 1][n - 1];
    }
};
// @lc code=end
