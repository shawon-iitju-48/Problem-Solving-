class Solution
{
public:
    int solve(int idx, vector<int> &nums, vector<int> &dp)
    {
        if (idx >= nums.size())
            return 0;

        if(dp[idx]!=-1)
        return dp[idx];

        for(int i=idx+1;i<nums)

    }
    int sumOfGoodSubsequences(vector<int> &nums)
    {
        vector<int> dpcount(nums.size(), -1);
        solve(0, nums, dp);
    }
};