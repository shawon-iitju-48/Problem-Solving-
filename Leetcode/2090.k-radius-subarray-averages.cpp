/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */

// @lc code=start
class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        long long div = k + k + 1, sum = 0, j = 0;
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (i - j >= div - 1)
            {
                ans[i - k] = sum / div;
                sum = sum - nums[j];
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end
