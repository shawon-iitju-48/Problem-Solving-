/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, int pi, vector<int> &count, vector<int> &ans, string &labels, vector<vector<int>> &adj)
    {
        int x = labels[i], age;
        x = x % 97;
        age = count[x];
        count[x]++;

        for (auto &j : adj[i])
        {
            if (j != pi)
                dfs(j, i, count, ans, labels, adj);
        }
        ans[i] = count[x] - age;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n, 0), count(26, 0);
        dfs(0, -1, count, ans, labels, adj);
        return ans;
    }
};
// @lc code=end
