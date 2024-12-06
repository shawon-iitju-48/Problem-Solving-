/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,mx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            cnt=0;
            else cnt++;
            mx=max(mx,cnt);
        }
        return mx;
    }
};
// @lc code=end

