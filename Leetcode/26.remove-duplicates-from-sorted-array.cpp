/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(ans[ans.size()-1]!=nums[i])
            ans.push_back(nums[i]);
        }
        for(int i=0;i<ans.size();i++)
        nums[i]=ans[i];
        return ans.size();
        
    }
};
// @lc code=end

