/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.empty())
            return 0;

        int start = 0, end = nums.size() - 1;
        while (start < end)
        {
            if (nums[start] == val)
            {
                swap(nums[start], nums[end]);
                end--;
            }
            else
                start++;
        }
        return (nums[start]==val)?start:start + 1;
    }
};
// @lc code=end
