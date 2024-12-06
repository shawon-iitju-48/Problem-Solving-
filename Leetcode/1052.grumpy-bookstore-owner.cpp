/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        queue<int> q;
        int i = 0, sum = 0, mx = 0, n = customers.size();
        vector<int> piche(n, 0);
        for (int j = n - 1; j >= 0; j--)
        {
            if (grumpy[j] == 0)
            {
                if (j < n - 1)
                    piche[j] = piche[j + 1] + customers[j];
                else
                    piche[j] = customers[j];
            }
            else if (j < n - 1)
                piche[j] = piche[j + 1];
        }
        for (int j = 0; j < customers.size(); j++)
        {
            sum += customers[j];
            if (grumpy[j])
                q.push(j);

            while (!q.empty() and j - q.front() >= minutes and grumpy[j])
                q.pop();

            if (!q.empty())
            {
                int x = q.front() - 1;
                while (x >= i and grumpy[x] == 0)
                    x--;
                for (int d = i; d <= x; d++)
                {
                    if (grumpy[d])
                        sum = sum - customers[d];
                }
                i = x + 1;
            }
            int x = sum;
            if (j + 1 < n)
                x += piche[j + 1];
            mx = max(mx, x);
        }
        return mx;
    }
};
// @lc code=end