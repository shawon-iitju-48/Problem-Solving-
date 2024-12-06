/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution
{
public:
    void dfs(int vertex, vector<bool> &visited, vector<vector<int>> &isConnected)
    {
        visited[vertex] = true;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (vertex != i and isConnected[vertex][i] == 1 and !visited[i])
                dfs(i, visited, isConnected);
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int cnt = 0, V = isConnected.size();
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                cnt++;
                dfs(i, visited, isConnected);
            }
        }
        return cnt;
    }
};
// @lc code=end
