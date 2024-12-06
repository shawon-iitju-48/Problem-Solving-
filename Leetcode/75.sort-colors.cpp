/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int start = 0, mid = 0, end = nums.size() - 1, i = 0;
        while (mid <= end)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[start]);
                start++;
                mid++;
                i++;
            }
            else if (nums[i] == 1)
            {
                mid++;
                i++;
            }
            else
            {
                swap(nums[i], nums[end]);
                end--;
            }
        }
    }
};
// @lc code=end
