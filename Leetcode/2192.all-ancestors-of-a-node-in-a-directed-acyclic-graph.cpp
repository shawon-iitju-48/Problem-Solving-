/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n), ans(n);
        vector<vector<bool>> tempans(n, vector<bool>(n, false));
        vector<int> indegree(n, 0);

        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                tempans[neighbor][node] = true;

                for (int i = 0; i < n; i++)
                {
                    if (tempans[node][i])
                        tempans[neighbor][i] = true;
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (tempans[i][j])
                    ans[i].push_back(j);
            }
        }

        return ans;
    }
};
// @lc code=end
