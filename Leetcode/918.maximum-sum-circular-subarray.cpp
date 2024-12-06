/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size(), mx = nums[0];

        vector<int> sumL(n, 0), sumR(n, 0);

        sumL[0] = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum += nums[i];
            sumL[i] = max(sum, sumL[i - 1]);
        }

        sumR[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            sumR[i] = nums[i] + sumR[i + 1];

        for (int i = 1; i < n; i++)
        {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
            mx = max(mx, nums[i]);
            mx = max(mx, sumR[i] + sumL[i - 1]);
        }
        return mx;
    }
};
// @lc code=end
