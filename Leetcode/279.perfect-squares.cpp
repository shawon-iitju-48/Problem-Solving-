/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> ps;
        for (int i = 1; i * i <= n; i++)
            ps.push_back(i * i);

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> vis(n + 1, false);

        while (!q.empty())
        {
            auto [sum, steps] = q.front();
            q.pop();

            if (sum == n)
                return steps;

            for (int i = 0; i < ps.size(); i++)
            {
                int presum = ps[i] + sum;
                if (presum <= n and !vis[presum])
                {
                    q.push({presum, steps + 1});
                    vis[presum] = true;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
