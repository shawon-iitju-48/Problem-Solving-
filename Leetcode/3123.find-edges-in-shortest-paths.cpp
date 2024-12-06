/*
 * @lc app=leetcode id=3123 lang=cpp
 *
 * [3123] Find Edges in Shortest Paths
 */

// @lc code=start
class Solution
{
public:
    void dijkstra(int start, vector<int> &res, vector<vector<pair<int, int>>> &adj)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, start});
        while (!q.empty())
        {
            int node = q.top().second;
            q.pop();
            for (auto &neighbor : adj[node])
            {
                if (res[node] + neighbor.second < res[neighbor.first])
                {
                    res[neighbor.first] = res[node] + neighbor.second;
                    q.push({res[neighbor.first], neighbor.first});
                }
            }
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> srctodes(n, 1e8), destosrc(n, 1e8);
        srctodes[0] = 0, destosrc[n - 1] = 0;
        dijkstra(0, srctodes, adj);
        dijkstra(n - 1, destosrc, adj);

        vector<bool> ans;
        for (auto &edge : edges)
        {
            int x = srctodes[edge[0]] + edge[2] + destosrc[edge[1]];
            int y = srctodes[edge[1]] + edge[2] + destosrc[edge[0]];
            if ((x == srctodes[n - 1] or y == srctodes[n - 1]) and srctodes[n - 1] != 1e8)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
// @lc code=end
