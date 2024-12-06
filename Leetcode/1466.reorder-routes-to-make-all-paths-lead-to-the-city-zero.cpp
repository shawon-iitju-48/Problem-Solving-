/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution
{
public:
    void dfs(int &cnt, int vertex, vector<bool> &visited, queue<int> &q, vector<vector<int>> &adj, unordered_map<int, vector<int>> &mp)
    {
        visited[vertex] = true;
        vector<int> v = mp[vertex];
        for (int i = 0; i < v.size(); i++)
        {
            if (!visited[v[i]])
                q.push(v[i]);
        }
        for (auto &j : adj[vertex])
        {
            if (!visited[j])
            {
                cnt++;
                dfs(cnt, j, visited, q, adj, mp);
            }
        }
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            mp[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        int cnt = 0;
        while (!q.empty())
        {
            dfs(cnt, q.front(), visited, q, adj, mp);
            q.pop();
        }
        return cnt;
    }
};
// @lc code=end
