/*
 * @lc app=leetcode id=2050 lang=cpp
 *
 * [2050] Parallel Courses III
 */

// @lc code=start
class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> indegree(n + 1, 0), startingTime(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < relations.size(); i++)
        {
            indegree[relations[i][1]]++;
            adj[relations[i][0]].push_back(relations[i][1]);
        }
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
                q.push({i, 0});
        }
        int ans = 0;
        while (!q.empty())
        {
            int node = q.front().first, startingat = q.front().second;
            q.pop();
            ans = max(ans, startingat + time[node - 1]);
            for (auto &j : adj[node])
            {
                startingTime[j] = max(startingTime[j], startingat + time[node - 1]);
                indegree[j]--;
                if (indegree[j] == 0)
                    q.push({j, startingTime[j]});
            }
        }
        return ans;
    }
};
// @lc code=end
