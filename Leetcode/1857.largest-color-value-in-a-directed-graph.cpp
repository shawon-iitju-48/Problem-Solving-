/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */

// @lc code=start
class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size(), nodeCount = 0;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                dp[i][colors[i] - 'a'] = 1;
            }
        }
        int ans = INT_MIN;
        while (!q.empty())
        {
            nodeCount++;
            int u = q.front();
            q.pop();
            ans = max(ans, dp[u][colors[u] - 'a']);
            for (auto &i : adj[u])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
                for (int j = 0; j < 26; j++)
                {
                    if (j == (colors[i] - 'a'))
                        dp[i][j] = max(dp[i][j], dp[u][j] + 1);
                    else
                        dp[i][j] = max(dp[i][j], dp[u][j]);
                    // ans = max(ans, dp[i][j]);
                }
            }
        }
        if (nodeCount < n)
            return -1;
        return ans;
    }
};
// @lc code=end
