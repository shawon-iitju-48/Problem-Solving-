/*
 * @lc app=leetcode id=1203 lang=cpp
 *
 * [1203] Sort Items by Groups Respecting Dependencies
 */

// @lc code=start
class Solution
{
public:
    vector<int> toposort(vector<vector<int>> &adj)
    {
        int N = adj.size();
        vector<int> in_degree(N, 0);
        vector<int> result;

        for (int i = 0; i < N; i++)
            for (int neighbor : adj[i])
                in_degree[neighbor]++;

        queue<int> q;
        for (int i = 0; i < N; i++)
            if (in_degree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            result.push_back(vertex);

            for (int neighbor : adj[vertex])
            {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if (result.size() != N)
            return {};

        return result;
    }
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        for (int i = 0; i < n; i++)
        {
            if (group[i] == -1)
                group[i] = m++;
        }
        vector<int> ans;
        vector<vector<int>> itemadj(n), groupadj(m);
        for (int i = 0; i < n; i++)
        {
            for (auto &j : beforeItems[i])
            {
                itemadj[j].push_back(i);
                if (group[i] != -1 and group[j] != -1 and group[j] != group[i])
                    groupadj[group[j]].push_back(group[i]);
            }
        }
        vector<int> sortedItems = toposort(itemadj), sortedGroups = toposort(groupadj);
        if (sortedItems.size() == 0 or sortedGroups.size() == 0)
            return {};

        vector<vector<int>> tempans(m);
        for (int i = 0; i < n; i++)
            tempans[group[sortedItems[i]]].push_back(sortedItems[i]);
        for (int i = 0; i < m; i++)
        {
            for (int &j : tempans[sortedGroups[i]])
                ans.push_back(j);
        }
        return ans;
    }
};
// @lc code=end
