/*
 * @lc app=leetcode id=2009 lang=cpp
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int mn = INT_MAX, target = n - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = upper_bound(nums.begin(), nums.end(), nums[i] + target);
            cout << int(distance(nums.begin() + i, it)) << " ";
            mn = min(mn, n - int(distance(nums.begin() + i, it)));
        }

        return mn;
    }
};
// @lc code=end
