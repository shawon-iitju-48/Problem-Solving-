/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
class Solution
{
public:
    int rootsum = 0;
    int dfs1(int currsum, int i, int pi, vector<vector<int>> &adj, vector<int> &count)
    {
        int sum = 0;
        for (auto &j : adj[i])
        {
            if (j != pi)
                sum += dfs1(currsum + 1, j, i, adj, count);
        }
        rootsum += currsum;
        return count[i] = 1 + sum;
    }
    void dfs2(int i, int pi, vector<int> &res, vector<int> &count, vector<vector<int>> &adj)
    {
        if (res[i] == -1)
            res[i] = res[pi] + adj.size() - (2 * count[i]);
        for (auto &j : adj[i])
        {
            if (pi != j)
                dfs2(j, i, res, count, adj);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> count(n, 0), res(n, -1);

        dfs1(0, 0, -1, adj, count);
        res[0] = rootsum;

        dfs2(0, -1, res, count, adj);
        return res;
    }
};
// @lc code=end
