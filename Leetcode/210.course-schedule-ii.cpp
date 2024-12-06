/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int V = numCourses;
        vector<int> adj[V];
        for (int i = 0; i < prerequisites.size(); i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);

        vector<int> indegree(V, 0), ans;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
                indegree[adj[i][j]]++;
        }
        queue<int> q;
        int temp, cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            cnt++;
            ans.push_back(temp);
            for (int i = 0; i < adj[temp].size(); i++)
            {
                indegree[adj[temp][i]]--;
                if (indegree[adj[temp][i]] == 0)
                    q.push(adj[temp][i]);
            }
        }
        if (cnt != V)
            return {};
        return ans;
    }
};
// @lc code=end
