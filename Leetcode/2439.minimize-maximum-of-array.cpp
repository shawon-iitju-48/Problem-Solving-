/*
 * @lc app=leetcode id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 */

// @lc code=start
class Solution
{
public:
    bool check(int target, vector<int> &nums)
    {
        long long x = target - nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - x > target)
                return false;

            x = target - nums[i] + x;
        }
        return true;
    }
    int minimizeArrayValue(vector<int> &nums)
    {
        int f = nums[0], l = 1e9, mid, ans;
        while (f <= l)
        {
            mid = f + (l - f) / 2;
            if (check(mid, nums))
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
