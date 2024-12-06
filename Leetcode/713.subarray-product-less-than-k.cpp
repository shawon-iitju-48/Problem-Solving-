/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int i = 0, sum = 0, prod = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            prod *= nums[j];
            while (prod >= k and i <= j)
            {
                prod = prod / nums[i];
                i++;
            }
            if (i <= j)
                sum = sum + j - i + 1;
        }
        return sum;
    }
};
// @lc code=end
