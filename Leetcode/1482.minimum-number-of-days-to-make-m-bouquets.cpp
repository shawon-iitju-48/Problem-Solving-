/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
class Solution
{
public:
    bool check(int targetday, vector<int> &bloomDay, int &m, int &k)
    {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= targetday)
                cnt2++;
            else
                cnt2 = 0;
            if (cnt2 == k)
            {
                cnt2 = 0;
                cnt1++;
            }
            if (cnt1 == m)
                return true;
        }
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long it a = m, b = k, need = a * b;
        if (bloomDay.size() < need)
            return -1;
        else
        {
            int f = INT_MAX, l = INT_MIN, mid, ans = 0;
            for (int i = 0; i < bloomDay.size(); i++)
            {
                f = min(f, bloomDay[i]);
                l = max(l, bloomDay[i]);
            }
            while (f <= l)
            {
                mid = f + (l - f) / 2;
                if (check(mid, bloomDay, m, k))
                {
                    l = mid - 1;
                    ans = mid;
                }
                else
                    f = mid + 1;
            }
            return ans;
        }
    }
};
// @lc code=end
