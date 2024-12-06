/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == 1e8 or dist[k][j] == 1e8)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= distanceThreshold)
                    ans[i]++;
            }
        }
        int mn = INT_MAX, minindex = -1;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] <= mn)
            {
                mn = ans[i];
                minindex = i;
            }
        }
        return minindex;
    }
};
// @lc code=end
