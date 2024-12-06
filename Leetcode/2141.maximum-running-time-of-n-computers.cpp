/*
 * @lc app=leetcode id=2141 lang=cpp
 *
 * [2141] Maximum Running Time of N Computers
 */

// @lc code=start
class Solution
{
public:
    bool check(long long minute, vector<int> &batteries, long long n)
    {
        long long sum = 0;
        for (int i = 0; i < batteries.size(); i++)
            sum += min((long long)batteries[i], minute);
        sum=sum/n;
        return sum >= minute;
    }
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long f = 1, l = 1e15, mid, ans;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            if (check(mid, batteries, n))
            {
                ans = mid;
                f = mid + 1;
            }
            else
                l = mid - 1;
        }
        return ans;
    }
};
// @lc code=end
