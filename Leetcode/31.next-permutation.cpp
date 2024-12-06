/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int flag = 0, target, start = 0, end = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                flag = 1;
                target = i;
                break;
            }
        }
        if (flag == 0)
        {
            while (start <= end)
            {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
        }
        else
        {
            start = target + 1;
            end = nums.size() - 1;
            while (start <= end)
            {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
            for (int i = target + 1; i < nums.size(); i++)
            {
                if (nums[i] > nums[target])
                {
                    swap(nums[target], nums[i]);
                    break;
                }
            }
        }
    }
};
// @lc code=end
