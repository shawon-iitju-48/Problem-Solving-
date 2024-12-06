/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start
class Solution
{
public:
    int dfs(int i, int pi, vector<vector<int>> &adj, vector<bool> &hasApple)
    {
        int sum = 0, flag = 0;
        for (auto &j : adj[i])
        {
            if (j != pi)
            {
                int x = dfs(j, i, adj, hasApple);
                if (x != INT_MAX)
                {
                    sum += 2 + x;
                    flag = 1;
                }
            }
        }

        if (flag == 1)
            return sum;

        if (hasApple[i])
            return 0;

        return INT_MAX;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = dfs(0, -1, adj, hasApple);
        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};
// @lc code=end
