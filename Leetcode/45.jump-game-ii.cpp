/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int curr = 0, far = 0, jump = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (curr >= nums.size() - 1)
                break;
            far = max(far, nums[i] + i);
            if (curr == i)
            {
                if (far > curr)
                {
                    jump++;
                    curr = far;
                }
            }
        }
        return jump;
    }
};

// @lc code=end
