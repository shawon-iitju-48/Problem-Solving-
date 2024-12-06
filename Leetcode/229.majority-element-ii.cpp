/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int me1 = nums[0], me2, cnt1 = 1, cnt2 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (me1 == nums[i])
                cnt1++;
            else if (me2 == nums[i])
                cnt2++;
            else if (cnt1 == 0)
                me1 = nums[i], cnt1++;
            else if (cnt2 == 0)
                me2 = nums[i], cnt2++;
            else if (nums[i] != me1 and nums[i] != me2)
            {
                cnt1--;
                cnt2--;
            }
        }
        int cnt = nums.size() / 3;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == me1)
                cnt1++;
            else if (nums[i] == me2)
                cnt2++;
        }
        vector<int> ans;
        if (cnt1 > cnt)
            ans.push_back(me1);
        if (cnt2 > cnt)
            ans.push_back(me2);
        return ans;
    }
};
// @lc code=end
