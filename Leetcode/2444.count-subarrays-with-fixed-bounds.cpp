/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 */

// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long start = -1, i = -1, mnI = -1, mxI = -1, sum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] < minK or nums[j] > maxK)
            {
                start = -1, mnI = -1, mxI = -1, i = -1;
                continue;
            }
            if (start == -1)
            {
                start = j;
                i = j;
            }
            if (nums[j] == minK)
                mnI = j;
            if (nums[j] == maxK)
                mxI = j;

            if (mnI > -1 and mxI > -1)
            {
                sum = sum + 1 + i - start;
                while (i < min(mnI, mxI))
                {
                    i++;
                    sum++;
                }
            }
        }
        return sum;
    }
};
// @lc code=end
