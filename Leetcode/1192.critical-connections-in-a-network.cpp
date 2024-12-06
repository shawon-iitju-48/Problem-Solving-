/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution
{
public:
    int cnt = 0;
    void dfs(int vertex, int parent, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &dt, vector<int> &lt, vector<vector<int>> &ans)
    {
        visited[vertex] = true;
        for (auto &neighbor : adj[vertex])
        {
            if (!visited[neighbor])
            {
                cnt++;
                dt[neighbor] = lt[neighbor] = cnt;
                dfs(neighbor, vertex, visited, adj, dt, lt, ans);
                if (dt[vertex] < lt[neighbor])
                    ans.push_back({vertex, neighbor});
                lt[vertex] = min(lt[neighbor], lt[vertex]);
            }
            else if (visited[neighbor] and neighbor != parent)
                lt[vertex] = min(lt[neighbor], lt[vertex]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> dt(n, 0), lt(n, 0); // discovery time, lowest time to get visited
        vector<vector<int>> adj(n), ans;
        for (auto &u : connections)
        {
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }
        vector<bool> visited(n, false);
        dfs(0, -1, visited, adj, dt, lt, ans);
        return ans;
    }
};
// @lc code=end
