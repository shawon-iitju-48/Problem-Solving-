/*
 * @lc app=leetcode id=2187 lang=cpp
 *
 * [2187] Minimum Time to Complete Trips
 */

// @lc code=start
class Solution
{
public:
    bool check(long long mnTime, vector<int> &time, int totalTrips)
    {
        long long cnt = 0;
        for (auto &t : time)
            cnt += (t / mnTime);
        return cnt >= totalTrips;
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long f = 1, l = 1e14, mid, ans;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            if (check(mid, time, totalTrips))
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
