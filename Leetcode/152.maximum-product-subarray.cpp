/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int mx = nums[0];
        vector<int> v(nums.size(), 0);
        v[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int x = max(nums[i], nums[i] * nums[i - 1]);
            x = max(x, nums[i] * v[i - 1]);
            mx = max(x, mx);
            int yx = min(nums[i], nums[i] * nums[i - 1]);
            yx = min(yx, nums[i] * v[i - 1]);
            v[i] = yx;
            nums[i] = x;
        }
        return mx;
    }
};
// @lc code=end
