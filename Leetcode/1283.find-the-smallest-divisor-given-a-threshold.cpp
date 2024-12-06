/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int f = 1, l = INT_MIN, mid, ans;
        for (int i = 0; i < nums.size(); i++)
            l = max(l, nums[i]);
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            int result = 0;
            for (int i = 0; i < nums.size(); i++)
                result += (nums[i] + mid - 1) / mid;
            if (result > threshold)
                f = mid + 1;
            else
            {
                l = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};
// @lc code=end
