class Solution
{
public:
    long long solve(int i, long long k, int flag, vector<int> &nums, vector<vector<vector<long long>>> &dp)
    {
        if (i >= nums.size() or k == 0)
            return 0;

        if (dp[i][k][flag] != LLONG_MIN)
            return dp[i][k][flag];

        long long sum = k * (long long)nums[i], mx = LLONG_MIN;
        if (flag == 0)
        {
            if (i < nums.size() - k)
            {
                mx = max(mx, solve(i + 1, k, flag, nums, dp));
                mx = max(mx, sum + solve(i + 1, k, 1, nums, dp));
            }
            mx = max(mx, sum + solve(i + 1, k - 1, 1, nums, dp));
        }
        else
        {
            if (k % 2 == 0)
                sum = -1 * sum;

            if (i < nums.size() - k)
                mx = max(mx, sum + solve(i + 1, k, flag, nums, dp));
            mx = max(mx, sum + solve(i + 1, k - 1, flag, nums, dp));
        }
        return dp[i][k][flag] = mx;
    }

    long long maximumStrength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k + 1, vector<long long>(2, LLONG_MIN)));
        return solve(0, k, 0, nums, dp);
    }
};
