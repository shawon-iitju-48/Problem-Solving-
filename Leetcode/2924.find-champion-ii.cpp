/*
 * @lc app=leetcode id=2924 lang=cpp
 *
 * [2924] Find Champion II
 */

// @lc code=start
class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {

        int cnt = 0, ans = -1;
        vector<int> indegree(n, 0);
        for (auto &e : edges)
            indegree[e[1]]++;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                cnt++;
                ans = i;
            }
        }
        return cnt > 1 ? -1 : ans;
    }
};
// @lc code=end
