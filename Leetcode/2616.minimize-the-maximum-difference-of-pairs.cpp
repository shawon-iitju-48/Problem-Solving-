/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
class Solution
{
public:
    bool check(int target, vector<int> &nums, int p)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]<=target)
            {
                p--;
                i++;
            }
        }
        return p<=0;
    }
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(begin(nums), end(nums));
        int f=0, l=1e9, mid, ans=0;
        while(f<=l)
        {
            mid=f+(l-f)/2;
            if(check(mid, nums, p))
            {
                ans=mid;
                l=mid-1;
            }
            else f=mid+1;
        }
        return ans;
    }
};
// @lc code=end
