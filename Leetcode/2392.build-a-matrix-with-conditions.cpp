/*
 * @lc app=leetcode id=2392 lang=cpp
 *
 * [2392] Build a Matrix With Conditions
 */

// @lc code=start
class Solution
{
public:
    vector<int> toposort(const vector<vector<int>> &adj)
    {
        int k = adj.size();
        vector<int> inDegree(k, 0);
        vector<int> sortedOrder;

        for (int i = 1; i < k; ++i)
        {
            for (int neighbor : adj[i])
                inDegree[neighbor]++;
        }
        queue<int> q;
        for (int i = 1; i < k; ++i)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            sortedOrder.push_back(node);
            for (int neighbor : adj[node])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        if (sortedOrder.size() != k - 1)
            return {};

        return sortedOrder;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<vector<int>> rowadj(k + 1), coladj(k + 1);
        for (auto &edge : rowConditions)
            rowadj[edge[0]].push_back(edge[1]);
        for (auto &edge : colConditions)
            coladj[edge[0]].push_back(edge[1]);
        vector<int> sortedrow = toposort(rowadj), sortedcol = toposort(coladj);
        if (sortedrow.size() == 0 or sortedcol.size() == 0)
            return {};
        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<int> vis(k + 1);
        for (int i = 0; i < k; i++)
            vis[sortedrow[i]] = i;
        int index = 0;
        for (int i = 0; i < k; i++)
        {
            int row = vis[sortedcol[i]];
            ans[row][index] = sortedcol[i];
            index++;
        }
        return ans;
    }
};
// @lc code=end
