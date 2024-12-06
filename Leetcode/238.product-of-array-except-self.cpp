/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>ans;
        int mul=1,lnn=nums.size();
        for(int i=0;i<lnn;i++)
        {
            mul*=nums[i];
            ans.push_back(mul);
        }
        mul=1;
        ans[lnn-1]=ans[lnn-2];
        for(int i=lnn-2;i>0;i--)
        {
            mul*=nums[i+1];
            ans[i]=ans[i-1]*mul;
        }
        ans[0]=mul*nums[1];
        return ans;
    }
};
// @lc code=end

