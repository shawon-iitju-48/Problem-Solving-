/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int V = numCourses;
        vector<int> adj[V];
        for (int i = 0; i < prerequisites.size(); i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);

        vector<int> indegree(V, 0);
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
            for (int i = 0; i < adj[temp].size(); i++)
            {
                indegree[adj[temp][i]]--;
                if (indegree[adj[temp][i]] == 0)
                    q.push(adj[temp][i]);
            }
        }
        if (cnt == V)
            return true;
        return false;
    }
};
