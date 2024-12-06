/* @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> resforred(n, INT_MAX), resforblue(n, INT_MAX);
        queue<vector<int>> q;
        q.push({0, 0, -1}); // red=1, blue=0, any=-1
        resforred[0] = 0;
        resforblue[0] = 0;

        vector<vector<pair<int, int>>> adj(n); // red=1, blue=0

        for (auto &red : redEdges)
            adj[red[0]].push_back({red[1], 1});
        for (auto &blue : blueEdges)
            adj[blue[0]].push_back({blue[1], 0});

        while (!q.empty())
        {
            int step = q.front()[0], node = q.front()[1], whichcolor = q.front()[2];
            q.pop();

            for (auto [neighbor, color] : adj[node])
            {
                if (whichcolor == -1)
                {
                    if (color == 1 and step + 1 < resforred[neighbor])
                    {
                        resforred[neighbor] = step + 1;
                        q.push({resforred[neighbor], neighbor, 1 - color});
                    }
                    else if (color == 0 and step + 1 < resforblue[neighbor])
                    {
                        resforblue[neighbor] = step + 1;
                        q.push({resforblue[neighbor], neighbor, 1 - color});
                    }
                }
                else
                {
                    if (color == whichcolor)
                    {
                        if (color == 1 and step + 1 < resforred[neighbor])
                        {
                            resforred[neighbor] = step + 1;
                            q.push({resforred[neighbor], neighbor, 1 - color});
                        }
                        else if (color == 0 and step + 1 < resforblue[neighbor])
                        {
                            resforblue[neighbor] = step + 1;
                            q.push({resforblue[neighbor], neighbor, 1 - color});
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            resforred[i] = min(resforred[i], resforblue[i]);
            if (resforred[i] == INT_MAX)
                resforred[i] = -1;
        }
        return resforred;
    }
};
// @lc code=end "