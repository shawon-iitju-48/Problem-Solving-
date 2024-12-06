/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        queue<vector<int>> q;
        int n = graph.size(), full_visit_mask = (1 << n) - 1; // right to left e nth bit set kore dibe (0-indexed)
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        for (int i = 0; i < n; i++)
        {
            q.push({i, 0, 1 << i});
            visited[i][1 << i] = true;
        }

        while (!q.empty())
        {
            int node = q.front()[0], step = q.front()[1], state = q.front()[2];
            q.pop();

            if (state == full_visit_mask)
                return step;

            for (int neighbor : graph[node])
            {
                int new_state = state | (1 << neighbor);
                if (!visited[neighbor][new_state])
                {
                    q.push({neighbor, step + 1, new_state});
                    visited[neighbor][new_state] = true;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
