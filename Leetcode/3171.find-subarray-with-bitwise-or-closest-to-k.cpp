/*
 * @lc app=leetcode id=3171 lang=cpp
 *
 * [3171] Find Subarray With Bitwise OR Closest to K
 */

// @lc code=start
class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        vector<int> freq(32, 0);
        int sum = 0, i = 0, mn = INT_MAX;
        for (int j = 0; j < nums.size(); j++)
        {
            mn = min(mn, abs(nums[j] - k));
            sum |= nums[j];
            for (int d = 0; d < 32; d++)
            {
                if (nums[j] & (1 << d))
                    freq[d]++;
            }
            while (sum > k and i < j)
            {
                mn = min(mn, abs(sum - k));
                for (int d = 0; d < 32; d++)
                {
                    if (nums[i] & (1 << d))
                    {
                        freq[d]--;
                        if (freq[d] == 0)
                        {
                            int mask = 1 << d;
                            int invertedMask = ~mask;
                            sum = sum & invertedMask;
                        }
                    }
                }
                i++;
            }
            mn = min(mn, abs(sum - k));
        }
        return mn;
    }
};
// @lc code=end
