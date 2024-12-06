/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<double> res(n, INT_MIN);
        res[start_node] = 1;
        double x;

        priority_queue<pair<double, int>> maxpq;
        maxpq.push({1.0, start_node});

        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        while (!maxpq.empty())
        {
            int node = maxpq.top().second;
            maxpq.pop();

            for (auto &j : adj[node])
            {
                x = res[node] * j.second;
                if (x > res[j.first])
                {
                    res[j.first] = x;
                    maxpq.push({x, j.first});
                }
            }
        }

        if (res[end_node] == INT_MIN)
            return 0;
        return res[end_node];
    }
};
// @lc code=end
