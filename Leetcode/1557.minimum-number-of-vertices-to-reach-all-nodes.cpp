/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start
class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {

        vector<int> ans, indegree(n, 0);
        for (int i = 0; i < edges.size(); i++)
            indegree[edges[i][1]]++;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                ans.push_back(i);
        return ans;
    }
};
// @lc code=end
