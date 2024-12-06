/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int first = 0, last = nums.size() - 1, mid;
        while (first <= last)
        {
            mid = (first + last) / 2;
            int age = INT_MIN, pore = INT_MAX;
            if (mid - 1 >= 0)
                age = nums[mid - 1];
            if (mid + 1 < nums.size())
                pore = nums[mid + 1];
            if (mid % 2 == 0)
            {
                if (nums[mid] != age and nums[mid] != pore)
                    return nums[mid];
                if (nums[mid] == pore)
                    first = mid + 1;
                else
                    last = mid - 1;
            }
            else
            {
                if (nums[mid] == pore)
                    last = mid - 1;
                else
                    first = mid + 1;
            }
        }
        return 0;
    }
};
// @lc code=end
