/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {

        int window = 0, mn = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                window++;
        }
        vector<int> freq(2, 0);
        for (int i = 0; i < window; i++)
            freq[nums[i]]++;
        mn = min(mn, freq[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            freq[nums[i - 1]]--;
            freq[nums[window % nums.size()]]++;
            mn = min(mn, freq[0]);
            window++;
        }
        return mn;
    }
};
// @lc code=end
