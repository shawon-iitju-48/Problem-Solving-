/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++)
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});

        queue<vector<int>> q;
        q.push({-1, src, 0});

        int ans = INT_MAX;
        vector<int> res(n, INT_MAX);
        res[src] = 0;

        while (!q.empty())
        {
            int cnt = q.front()[0], node = q.front()[1], currsum = q.front()[2];
            q.pop();

            if (node == dst)
                ans = min(ans, currsum);

            for (auto &item : adj[node])
            {
                if (cnt + 1 <= k && currsum + item.second <= res[item.first])
                {
                    q.push({cnt + 1, item.first, currsum + item.second});
                    res[item.first] = currsum + item.second;
                }
            }
        }

        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};

// @lc code=end
