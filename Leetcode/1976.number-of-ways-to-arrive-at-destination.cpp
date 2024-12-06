/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */

// @lc code=start
class Solution
{
public:
    int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<long long, long long>>> adj(n);
        for (auto &road : roads)
        {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q; // Change to long long
        vector<long long> res(n, LLONG_MAX), dp(n, 0);
        q.push({0, 0});
        res[0] = 0;
        dp[0] = 1;

        while (!q.empty())
        {
            auto [dist, node] = q.top();
            q.pop();
            for (auto [neighbor, w] : adj[node])
            {
                if (res[node] + w < res[neighbor])
                {
                    res[neighbor] = res[node] + w;
                    dp[neighbor] = dp[node];
                    q.push({res[neighbor], neighbor});
                }
                else if (res[node] + w == res[neighbor])
                    dp[neighbor] = (dp[neighbor] + dp[node]) % mod;
            }
        }

        return dp[n - 1];
    }
};
// @lc code=end
