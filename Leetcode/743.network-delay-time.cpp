/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution
{
public:
    int shortestPath(int n, vector<vector<int>> &edges, int S)
    {
        vector<vector<int>> adj[n + 1];
        for (int i = 0; i < edges.size(); i++)
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});

        vector<int> res(n + 1, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;
        res[S] = 0;
        minpq.push({0, S});
        int dist, d, node;
        while (!minpq.empty())
        {
            dist = minpq.top().first;
            node = minpq.top().second;
            minpq.pop();

            for (int i = 0; i < adj[node].size(); i++)
            {
                d = dist + adj[node][i][1];
                if (d < res[adj[node][i][0]])
                {
                    minpq.push({d, adj[node][i][0]});
                    res[adj[node][i][0]] = d;
                }
            }
        }
        int mx = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (res[i] == INT_MAX)
                return -1;
            mx = max(mx, res[i]);
        }
        return mx;
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        return shortestPath(n, times, k);
    }
};
// @lc code=end
