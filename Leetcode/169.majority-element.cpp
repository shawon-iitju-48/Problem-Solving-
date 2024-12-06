/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cm=nums[0],cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=cm)
            cnt--;
            else cnt++;
            if(cnt==0)
            {
                cnt++;
                cm=nums[i];
            }
        }
        return cm;
    }
};
// @lc code=end

