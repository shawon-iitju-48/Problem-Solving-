/*
 * @lc app=leetcode id=2477 lang=cpp
 *
 * [2477] Minimum Fuel Cost to Report to the Capital
 */

// @lc code=start
class Solution
{
public:
    long long ans = 0;
    int dfs(int vertex, int pi, vector<vector<int>> &adj, int &seats)
    {
        int pass = 0;
        for (auto &neighbor : adj[vertex])
        {
            if (neighbor != pi)
                pass += dfs(neighbor, vertex, adj, seats);
        }
        pass++;
        if (vertex != 0)
            ans += (pass + seats - 1) / seats;
        return pass;
    }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto &road : roads)
        {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        dfs(0, -1, adj, seats);
        return ans;
    }
};

// @lc code=end
