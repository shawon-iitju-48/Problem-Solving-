/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */

// @lc code=start
class Solution
{
public:
    int dfs(int vertex, vector<int> &visited, vector<int> adj[])
    {
        visited[vertex] = 1;
        int cnt = 0;
        for (int i = 0; i < adj[vertex].size(); i++)
            if (visited[adj[vertex][i]] == 0)
                cnt += dfs(adj[vertex][i], visited, adj);
        return 1 + cnt;
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n], visited(n, 0);
        vector<long long> v;
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
                v.push_back(dfs(i, visited, adj));
        }
        long long ans = 0;
        for (int i = v.size() - 2; i >= 0; i--)
        {
            ans = ans + (v[i + 1] * v[i]);
            v[i] = v[i] + v[i + 1];
        }
        return ans;
    }
};
// @lc code=end
