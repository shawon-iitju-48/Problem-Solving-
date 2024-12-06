/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int cnt = 0, flag = 0, index;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (flag == 1)
                cnt++;
            if ((nums[i] > cnt or (index == nums.size() - 1 and nums[i] >= cnt)) and flag == 1)
            {
                flag = 0;
                cnt = 0;
                index = -1;
            }
            if (nums[i] == 0 and flag == 0)
            {
                cnt = 0;
                flag = 1;
                index = i;
            }
        }
        if (flag == 1)
            return false;
        else
            return true;
    }
};
// @lc code=end
