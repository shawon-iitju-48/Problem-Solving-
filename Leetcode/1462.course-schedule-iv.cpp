class Solution
{
public:
    void dfs(int p, int i, vector<vector<int>> &adj, vector<vector<bool>> &parent)
    {
        if (parent[p][i])
            return;
        parent[p][i] = true;
        for (auto &neighbor : adj[i])
            dfs(p, neighbor, adj, parent);
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(numCourses);
        for (auto &course : prerequisites)
            adj[course[0]].push_back(course[1]);

        vector<vector<bool>> parent(numCourses, vector<bool>(numCourses, false));
        vector<bool> ans;

        for (int i = 0; i < numCourses; i++)
            dfs(i, i, adj, parent);

        for (auto &q : queries)
            ans.push_back(parent[q[0]][q[1]]);
        return ans;
    }
};
