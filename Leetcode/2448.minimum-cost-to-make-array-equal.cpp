/*
 * @lc app=leetcode id=2448 lang=cpp
 *
 * [2448] Minimum Cost to Make Array Equal
 */

// @lc code=start
class Solution
{
public:
    long long check(long long target, vector<int> &nums, vector<int> &cost)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += (long long)abs(target - nums[i]) * (long long)cost[i];
        return sum;
    }
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        long long ans, f = 1, l = 1e6, mid;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            long long x = check(mid, nums, cost), y = check(mid + 1, nums, cost);
            if (x < y)
            {
                l = mid - 1;
                ans = x;
            }
            else
            {
                f = mid + 1;
                ans = y;
            }
        }
        return ans;
    }
};
// @lc code=end
