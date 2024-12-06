/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {

        vector<int> indegree(n + 1, 0), vis(n + 1, 0);
        for (auto &person : trust)
        {
            indegree[person[1]]++;
            vis[person[0]] = 1;
        }

        for (int i = 1; i <= n; i++)
            if (indegree[i] == n - 1 and vis[i] == 0)
                return i;
        return -1;
    }
};
// @lc code=end
