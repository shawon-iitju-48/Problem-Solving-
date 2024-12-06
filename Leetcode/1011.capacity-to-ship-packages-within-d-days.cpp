/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution
{
public:
    bool check(int container, vector<int> &weights, int &days)
    {
        int daycount = 1, sum = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if (sum > container)
            {
                sum = weights[i];
                daycount++;
            }
            if (daycount > days)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int f = INT_MIN, l = 0, mid, ans;
        for (int i = 0; i < weights.size(); i++)
        {
            f = max(f, weights[i]);
            l += weights[i];
        }
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            if (check(mid, weights, days))
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
