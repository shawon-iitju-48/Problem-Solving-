/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution
{
public:
    bool bfs(int vertex, vector<bool> &visited, vector<vector<int>> &graph, vector<int> &set)
    {
        queue<int> q;
        q.push(vertex);
        int num;

        while (!q.empty())
        {
            num = q.front();
            q.pop();
            visited[num] = true;

            for (int i = 0; i < graph[num].size(); i++)
            {
                if (set[num] == set[graph[num][i]])
                    return false;

                if (set[num] == 1)
                    set[graph[num][i]] = 2;
                else if (set[num] == 2)
                    set[graph[num][i]] = 1;

                if (!visited[graph[num][i]])
                    q.push(graph[num][i]);
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<bool> visited(graph.size(), false);
        vector<int> set(graph.size(), 0);

        for (int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
            {
                set[i] = 1;
                if (bfs(i, visited, graph, set) == false)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
