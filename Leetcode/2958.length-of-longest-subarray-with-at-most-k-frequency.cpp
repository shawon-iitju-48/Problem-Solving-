/*
 * @lc app=leetcode id=2958 lang=cpp
 *
 * [2958] Length of Longest Subarray With at Most K Frequency
 */

// @lc code=start
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int j = 0, mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            while (mp[nums[i]] > k)
            {
                mp[nums[j]]--;
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return mx;
    }
};
// @lc code=end
