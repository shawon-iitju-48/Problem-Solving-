/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int store_point = 1, cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                cnt++;
            else
                cnt = 1;

            if (cnt <= 2)
            {
                nums[store_point] = nums[i];
                store_point++;
            }
        }
        return store_point;
    }
};
// @lc code=end
