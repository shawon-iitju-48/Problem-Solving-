/*
 * @lc app=leetcode id=2290 lang=cpp
 *
 * [2290] Minimum Obstacle Removal to Reach Corner
 */

// @lc code=start
class Solution
{
public:
    void dijkstra(int start, vector<vector<pair<int, int>>> &graph, vector<int> &distances)
    {
        distances[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dist > distances[node])
                continue;
            for (auto &neighbor : graph[node])
            {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                if (distances[node] + weight < distances[nextNode])
                {
                    distances[nextNode] = distances[node] + weight;
                    pq.push({distances[nextNode], nextNode});
                }
            }
        }
    }
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), total = m * n;

        vector<vector<pair<int, int>>> adj(total);
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int u = n * i + j;
                for (int d = 0; d < 4; d++)
                {
                    int newI = i + dir[d].first;
                    int newJ = j + dir[d].second;
                    if (newI >= 0 and newJ >= 0 and newI < m and newJ < n)
                    {
                        int v = n * newI + newJ;
                        adj[u].push_back({v, grid[i][j]});
                    }
                }
            }
        }

        vector<int> dist(total, INT_MAX);
        dijkstra(0, adj, dist);

        return dist[total - 1];
    }
};
// @lc code=end
