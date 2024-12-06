/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 */

// @lc code=start
class Solution
{
public:
    int mx = INT_MIN;
    bool dfs(int i, int cnt, vector<bool> &visited, vector<bool> &inRecursion, vector<int> &edges)
    {
        visited[i] = true;
        inRecursion[i] = true;
        int temp = edges[i];
        edges[i] = cnt;

        if (temp != -1)
        {
            if (!visited[temp] and dfs(temp, cnt + 1, visited, inRecursion, edges))
            {
                inRecursion[i] = false;
                return true;
            }
            else if (inRecursion[temp])
            {
                mx = max(mx, cnt - edges[temp] + 1);
                inRecursion[i] = false;
                return true;
            }
        }
        inRecursion[i] = false;
        return false;
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<bool> visited(n, false), inRecursion(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs(i, 0, visited, inRecursion, edges);
        }
        if (mx == INT_MIN)
            return -1;
        return mx;
    }
};
// @lc code=end
