/*
 * @lc app=leetcode id=2920 lang=cpp
 *
 * [2920] Maximum Points After Collecting Coins From All Nodes
 */

// @lc code=start
class Solution
{
public:
    vector<int> power;
    int solve(int node, int reduction_index, vector<vector<int>> &adj, vector<int> &coins, int &k, vector<bool> &vis, vector<vector<int>>&dp)
    {
        if(dp[node][reduction_index]!=-1)
        re
        if (reduction_index >= 15)
            reduction_index = 14;

        vis[node] = true;
        int coin = coins[node] / power[reduction_index];
        int optionA = coin - k, optionB = coin / 2;

        if (coin - k < 0)
            optionA = -1 * abs(coin - k);

        for (auto &neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                optionA = optionA + solve(neighbor, reduction_index, adj, coins, k, vis,dp);
                optionB = optionB + solve(neighbor, reduction_index + 1, adj, coins, k, vis,dp);
            }
        }
        vis[node] = false;
        return dp[node][reduction_index]=(optionA, optionB);
    }
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        int n = coins.size();

        vector<vector<int>> adj(n);

        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        power.resize(15, 1);
        power[1] = 2;
        for (int i = 2; i < 15; i++)
            power[i] = 2 * power[i - 1];

        vector<bool> vis(n, false);
        vector<vector<int>>dp(n, vector<int>(15,-1));
        return solve(0, 0, adj, coins, k, vis,dp);
    }
};
// @lc code=end