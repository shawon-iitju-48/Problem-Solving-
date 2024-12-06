/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, int &cnt, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[i] = true;
        int sum = 0;
        for (auto &j : adj[i])
        {
            if (!vis[j])
            {
                dfs(j, cnt, vis, adj);
                cnt++;
            }
        }
    }
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        long long n = bombs.size(), x, y, r;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    x = (bombs[i][0] - bombs[j][0]);
                    y = (bombs[i][1] - bombs[j][1]);
                    r = bombs[i][2];
                    if (x * x + y * y <= r * r)
                        adj[i].push_back(j);
                }
            }
        }
        int mx = INT_MIN;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            vis.assign(n, false);
            dfs(i, cnt, vis, adj);
            mx = max(mx, cnt);
        }
        return mx;
    }
};
// @lc code=end
