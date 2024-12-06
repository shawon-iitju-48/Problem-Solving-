/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> ans;
    void dfs(vector<int> v, int i, vector<bool> &visited, vector<vector<int>> &graph)
    {
        visited[i] = true;

        for (auto &j : graph[i])
        {
            if (!visited[j])
            {
                v.push_back(j);
                dfs(v, j, visited, graph);
                v.pop_back();
            }
        }

        if (i == graph.size() - 1)
            ans.push_back(v);

        visited[i] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<bool> visited(graph.size(), false);
        dfs({0}, 0, visited, graph);
        return ans;
    }
};
// @lc code=end
