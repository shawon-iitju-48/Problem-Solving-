/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0, x;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            x = sum % k;
            if (x < 0)
                x += k;
            if (mp.find(x) != mp.end())
                ans += mp[x];
            mp[x]++;
        }
        return ans;
    }
};
// @lc code=end
