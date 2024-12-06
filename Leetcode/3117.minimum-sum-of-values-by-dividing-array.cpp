/*
 * @lc app=leetcode id=3117 lang=cpp
 *
 * [3117] Minimum Sum of Values by Dividing Array
 */

// @lc code=start
class Solution
{
public:
    int solve(int i, int j, int andVal, vector<int> &nums, vector<int> &andValues, vector<vector<unordered_map<int, int>>> &dp)
    {
        if (i >= nums.size())
            return j >= andValues.size() ? 0 : INT_MAX;

        if (j >= andValues.size())
            return INT_MAX;

        if (dp[i][j].count(andVal))
            return dp[i][j][andVal];

        int newVal = andVal & nums[i], right = INT_MAX, left = INT_MAX;

        if (newVal == andValues[j])
            left = solve(i + 1, j + 1, -1, nums, andValues, dp);

        right = solve(i + 1, j, newVal, nums, andValues, dp);

        left = left == INT_MAX ? INT_MAX : nums[i] + left;

        return dp[i][j][andVal] = min(left, right);
    }
    int minimumValueSum(vector<int> &nums, vector<int> &andValues)
    {
        int n = nums.size(), m = andValues.size();
        vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(m));
        int res = solve(0, 0, -1, nums, andValues, dp);
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
