/*
 * @lc app=leetcode id=1870 lang=cpp
 *
 * [1870] Minimum Speed to Arrive on Time
 */

// @lc code=start
class Solution
{
public:
    bool check(int target, vector<int> &dist, double hour)
    {
        double taken = 0, x;
        for (int i = 0; i < dist.size(); i++)
        {
            x = (dist[i] * 1.00) / target;
            taken += x;
            if (i == dist.size() - 1)
                return taken <= hour;
            taken = ceil(taken);
        }
        reurn false;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int f = 1, l = 1e7, mid, ans = -1;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            if (check(mid, dist, hour))
            {
                ans = mid;
                l = mid - 1;
            }
            else
                f = mid + 1;
        }
        return ans;
    }
};
// @lc code=end
