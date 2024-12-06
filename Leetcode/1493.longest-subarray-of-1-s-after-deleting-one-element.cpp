/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int sum = 0, longestSum = 0, mx = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                mx = max(mx, longestSum + sum);
                longestSum = sum;
                sum = 0;
            }
            else
                sum++;
        }

        if (mx == -1)
            return nums.size() - 1;

        if (sum > 0)
            mx = max(mx, longestSum + sum);

        return mx;
    }
};
// @lc code=end
