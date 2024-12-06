/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution
{
public:
    int k;
    long long solve(int idx, vector<int> &nums, vector<long long> &dp)
    {
        if (idx >= nums.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];
            
        long long mx = 0, mxElement = -1, numOfElement;
        for (int i = idx; i < idx + k and i < nums.size(); i++)
        {
            mxElement = max(mxElement, (long long)nums[i]);
            numOfElement = i - idx + 1;
            mx = max(mx, numOfElement * mxElement + solve(i + 1, nums, dp));
        }
        return dp[idx] = mx;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int kk)
    {
        k = kk;
        vector<long long> dp(arr.size(), -1);
        return solve(0, arr, dp);
    }
};
// @lc code=end
