/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    //Lazy sorting= nlogn time complexity
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> sorted;
        sorted.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
            if (it == sorted.end())
                sorted.push_back(nums[i]);
            else
                sorted[it - sorted.begin()] = nums[i];
        }
        return sorted.size();
    }
};
// @lc code=end
