/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            if (mp.find(sum - k) != mp.end())
                cnt += mp[sum - k];
            mp[sum]++;
        }
        return cnt;
    }
};
// @lc code=end
