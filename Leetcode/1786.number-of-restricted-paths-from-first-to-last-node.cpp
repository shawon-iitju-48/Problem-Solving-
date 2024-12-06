/*
 * @lc app=leetcode id=1786 lang=cpp
 *
 * [1786] Number of Restricted Paths From First to Last Node
 */

// @lc code=start
class Solution
{
public:
    void dijkstra(int source, vector<int> &res, vector<vector<pair<int, int>>> &adj)
    {
        res[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, source});

        while (!q.empty())
        {
            auto [dist, node] = q.top();
            q.pop();

            for (auto &neighbor : adj[node])
            {
                if (neighbor.second + dist < res[neighbor.first])
                {
                    res[neighbor.first] = neighbor.second + dist;
                    q.push({res[neighbor.first], neighbor.first});
                }
            }
        }
    }
    const int MOD = 1e9 + 7;
    int solve(int node, int &n, vector<int> &minDist, vector<vector<pair<int, int>>> &adj, vector<int> &dp)
    {
        if (node == n)
            return 1;

        if (dp[node] != -1)
            return dp[node];

        int cnt = 0;
        for (auto &neighbor : adj[node])
        {
            if (minDist[node] > minDist[neighbor.first])
                cnt = (cnt + solve(neighbor.first, n, minDist, adj, dp)) % MOD;
        }
        return dp[node] = cnt;
    }
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        vector<int> minDist(n + 1, INT_MAX);

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        dijkstra(n, minDist, adj);

        vector<int> dp(n + 1, -1);
        return solve(1, n, minDist, adj, dp);
    }
};
// @lc code=end
