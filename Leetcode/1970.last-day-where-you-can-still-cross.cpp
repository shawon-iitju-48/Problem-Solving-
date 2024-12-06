/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 */

// @lc code=start
class Solution
{
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool check(int targetDay, vector<vector<int>> &flood)
    {
        int m = flood.size(), n = flood[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int j = 0; j < n; j++)
        {
            if (flood[0][j] > targetDay)
            {
                q.push({0, j});
                vis[0][j] = true;
            }
        }
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            if (i == m - 1)
                return true;

            for (auto [x, y] : dir)
            {
                int newI = i + x;
                int newJ = j + y;
                if (newI >= 0 and newJ >= 0 and newI < m and newJ < n and !vis[newI][newJ] and flood[newI][newJ] > targetDay)
                {
                    q.push({newI, newJ});
                    vis[newI][newJ] = true;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        vector<vector<int>> flood(row, vector<int>(col, -1));
        for (int i = 0; i < cells.size(); i++)
            flood[cells[i][0] - 1][cells[i][1] - 1] = i + 1;

        int ans = 0, f = 1, l = row * col, mid;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            if (check(mid, flood))
            {
                ans = mid;
                f = mid + 1;
            }
            else
                l = mid - 1;
        }
        return ans;
    }
};
// @lc code=end
