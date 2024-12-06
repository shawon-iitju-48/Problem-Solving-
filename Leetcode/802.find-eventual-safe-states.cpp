/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution
{
public:
    bool cycledfs(int vertex, vector<bool> &visited, vector<bool> &inRecursion, vector<vector<int>> &graph)
    {
        visited[vertex] = true;
        inRecursion[vertex] = true;

        for (auto &i : graph[vertex])
        {
            if (!visited[i] and cycledfs(i, visited, inRecursion, graph) == true)
                return true;
            else if (inRecursion[i])
                return true;
        }
        inRecursion[vertex] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> res;
        vector<bool> visited(graph.size(), false), inRecursion(graph.size(), false);
        for (int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
                cycledfs(i, visited, inRecursion, graph);
        }
        for (int i = 0; i < graph.size(); i++)
        {
            if (!inRecursion[i])
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
