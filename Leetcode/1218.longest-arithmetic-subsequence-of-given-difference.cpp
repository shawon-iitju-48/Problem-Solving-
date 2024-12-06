/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 */

// @lc code=start
class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> dp;
        int mx = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            dp[arr[i]] = max(dp[arr[i]], 1 + dp[arr[i] - difference]);
            mx = max(mx, dp[arr[i]]);
        }
        return mx;
    }
};
// @lc code=end
