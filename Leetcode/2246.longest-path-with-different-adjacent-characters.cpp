/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 */

// @lc code=start
class Solution
{
public:
    int mx = INT_MIN;
    int dfs(int i, int pi, vector<vector<int>> &adj, string &s)
    {
        int first = 0, second = 0, x;
        for (auto &j : adj[i])
        {
            if (pi != j)
            {
                if (s[j] == s[i])
                    dfs(j, i, adj, s);
                else
                {
                    x = 1 + dfs(j, i, adj, s);

                    if (x > first and x <= second)
                        first = x;
                    else if (x > second)
                    {
                        first = second;
                        second = x;
                    }
                }
            }
        }
        mx = max(mx, first + second);
        return second;
    }
    int longestPath(vector<int> &parent, string s)
    {
        int n = s.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < parent.size(); i++)
        {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        dfs(0, -1, adj, s);
        return mx + 1;
    }
};
// @lc code=end
