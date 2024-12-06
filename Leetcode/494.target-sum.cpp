/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution
{
public:
    int targetsum(int i, int sum, int &target, vector<int> &nums, unordered_map<string, int> &mp)
    {
        string key = to_string(i) + "," + to_string(sum);
        if (i == nums.size())
        {
            if (sum == target)
                return 1;
            else
                return 0;
        }
        if (mp.find(key) != mp.end())
            return mp[key];
        int plus = targetsum(i + 1, sum + nums[i], target, nums, mp);
        int minus = targetsum(i + 1, sum - nums[i], target, nums, mp);
        return mp[key] = plus + minus;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        unordered_map<string, int> mp;
        return targetsum(0, 0, target, nums, mp);
    }
};
// @lc code=end
