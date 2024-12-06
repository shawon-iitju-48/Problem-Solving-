/*
 * @lc app=leetcode id=2642 lang=cpp
 *
 * [2642] Design Graph With Shortest Path Calculator
 */

// @lc code=start
class Graph
{
public:
    vector<vector<int>> dist;
    Graph(int n, vector<vector<int>> &edges)
    {
        dist.resize(n, vector<int>(n, INT_MAX));
        for (auto &edge : edges)
            dist[edge[0]][edge[1]] = edge[2];

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge)
    {
        if (dist[edge[0]][edge[1]] <= edge[2])
            return;

        dist[edge[0]][edge[1]] = edge[2];

        int k = edge[0], n = dist.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        k = edge[1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int shortestPath(int node1, int node2)
    {
        if (dist[node1][node2] == INT_MAX)
            return -1;
        return dist[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end