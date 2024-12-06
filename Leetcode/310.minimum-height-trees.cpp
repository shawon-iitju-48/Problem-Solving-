/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};

        vector<int> indegree(n, 0), vis(n, 0);
        vector<vector<int>> adj(n);

        for (auto &edge : edges)
        {
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
                q.push(i);
        }

        int remainingNodes = n;
        while (remainingNodes > 2)
        {
            int leafCount = q.size();
            remainingNodes -= leafCount;

            for (int i = 0; i < leafCount; i++)
            {
                int node = q.front();
                q.pop();
                for (auto &neighbor : adj[node])
                {
                    if (--indegree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
// @lc code=end
