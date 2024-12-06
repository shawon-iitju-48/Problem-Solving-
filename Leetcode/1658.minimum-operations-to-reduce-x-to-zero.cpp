/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int mn = INT_MAX, sum = 0, n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            mp[sum] = i;
            if (sum == x)
                mn = min(mn, i + 1);
        }
        mp[0] = -1;
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += nums[i];
            if (sum == x)
                mn = min(mn, n - i);
            if (mp.find(x - sum) != mp.end() and mp[x - sum] < i)
                mn = min(mn, mp[x - sum] + 1 + n - i);
        }
        if (mn == INT_MAX)
            return -1;
        return mn;
    }
};
// @lc code=end
