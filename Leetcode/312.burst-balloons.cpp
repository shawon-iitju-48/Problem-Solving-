class Solution
{
public:
    int burstballoons(int start, int end, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];

        int mx = 0;
        for (int k = start; k <= end; k++)
        {
            int profit = nums[start - 1] * nums[k] * nums[end + 1];
            mx = max(mx, burstballoons(start, k - 1, nums, dp) + profit + burstballoons(k + 1, end, nums, dp));
        }

        return dp[start][end] = mx;
    }

    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1); // Add boundary at the start
        nums.push_back(1);            // Add boundary at the end

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Initialize DP table with -1
        return burstballoons(1, n - 2, nums, dp);      // Valid range
    }
};