/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            int ache=target-nums[i];
            if(mp[ache]>0)
            {
                ans.push_back(mp[ache]-1);
                ans.push_back(i);
                break;
            }
            mp[nums[i]]=i+1;
        }
        return ans;
    }
};
// @lc code=end

