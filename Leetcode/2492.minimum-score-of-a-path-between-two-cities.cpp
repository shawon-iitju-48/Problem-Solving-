/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
class Solution
{
public:
    int mn = INT_MAX;
    void dfs(int i, vector<bool> &visited, vector<vector<pair<int, int>>> &adj)
    {
        visited[i] = visited;
        for (auto &j : adj[i])
        {
            mn = min(mn, j[1]);
            if (!visited[j[0]])
                dfs(j[0], visited, adj);
        }
    }
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<bool> visited;
        dfs(1, visited, adj);
        return mn;
    }
};
// @lc code=end
