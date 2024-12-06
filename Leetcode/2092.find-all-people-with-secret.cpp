/*
 * @lc app=leetcode id=2092 lang=cpp
 *
 * [2092] Find All People With Secret
 */

// @lc code=start

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        vector<vector<pair<int, int>>> adj(n);
        vector<bool> knows(n, false);
        vector<int> knowstime(n, INT_MAX);
        for (auto &m : meetings)
        {
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({firstPerson, 0});
        knows[0] = true, knows[firstPerson] = true;
        knowstime[0] = 0, knowstime[firstPerson] = 0;
        while (!q.empty())
        {
            int node = q.front().first, knowingTime = q.front().second;
            q.pop();
            for (auto &neighbor : adj[node])
            {
                if (knowstime[neighbor.first] > neighbor.second and neighbor.second >= knowingTime)
                {
                    q.push({neighbor.first, neighbor.second});
                    knows[neighbor.first] = true;
                    knowstime[neighbor.first] = neighbor.second;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (knows[i])
                ans.push_back(i);
        return ans;
    }
};
// @lc code=end
