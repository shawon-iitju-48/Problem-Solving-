/*
 * @lc app=leetcode id=1553 lang=cpp
 *
 * [1553] Minimum Number of Days to Eat N Oranges
 */

// @lc code=start
class Solution
{
public:
    int minDays(int n)
    {
        unordered_map<int, int> dp;
        queue<pair<int, int>> q;
        q.push({n, 0});
        while (!q.empty())
        {
            auto [node, step] = q.front();
            q.pop();

            if (node == 0)
                return step;
            if (dp.count(node - 1) == 0)
            {
                q.push({node - 1, step + 1});
                dp[node - 1] = 1;
            }
            if (node % 2 == 0 and dp.count(node / 2) == 0)
            {
                q.push({node / 2, step + 1});
                dp[node / 2] = 1;
            }
            if (node % 3 == 0 and dp.count(node / 3) == 0)
            {
                q.push({node / 3, step + 1});
                dp[node / 3] = 1;
            }
        }
        return -1;
    }
};
// @lc code=end
