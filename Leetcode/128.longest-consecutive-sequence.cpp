// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem128.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>ust(nums.begin(),nums.end());
        int mx=0,cur;
        for(int i=0;i<nums.size();i++)
        {
            if(ust.find(nums[i]+1)==ust.end())
            {
                cur=nums[i];
                while(ust.find(cur)!=ust.end())
                cur--;
                mx=max(mx,nums[i]-cur);
            }
        }
        return mx;
    }
};
// @lc code=end

