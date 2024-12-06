/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> res(n, vector<int>(n, INT_MAX));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        res[0][0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({grid[0][0], 0, 0});

        while (!q.empty())
        {
            int dist = q.top()[0], i = q.top()[1], j = q.top()[2];
            q.pop();

            if (i == n - 1 and j == n - 1)
                return res[i][j];

            for (auto [di, dj] : directions)
            {
                int ni = i + di;
                int nj = j + dj;

                if (ni >= 0 && ni < n && nj >= 0 && nj < n && max(res[i][j], grid[ni][nj]) < res[ni][nj])
                {
                    res[ni][nj] = max(res[i][j], grid[ni][nj]);
                    q.push({res[ni][nj], ni, nj});
                }
            }
        }
        return -1;
    }
};
// @lc code=end
