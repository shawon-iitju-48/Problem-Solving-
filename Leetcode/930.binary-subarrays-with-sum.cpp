/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int cnt = 0, mx = 0, j = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (j < i and nums[j] == 0)
            {
                cnt++;
                j++;
            }
            if (sum > goal)
            {
                if (j < i)
                {
                    sum = sum - nums[j];
                    j++;
                    cnt = 0;
                    while (j < i and nums[j] == 0)
                    {
                        cnt++;
                        j++;
                    }
                }
            }
            if (sum == goal)
                mx += 1 + cnt;
        }
        return mx;
    }

    //next task, leetcode-560
};
// @lc code=end
