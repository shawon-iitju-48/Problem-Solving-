class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int n = nums.size();
        vector<int> dp(n, 1);    // dp[i] will store the length of LIS ending at index i
        vector<int> count(n, 1); // count[i] will store the number of LIS ending at index i

        int mx = 1;  // To track the maximum length of LIS
        int cnt = 0; // To store the count of LIS of maximum length

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j]) // If nums[i] can extend the subsequence ending at nums[j]
                {
                    if (dp[i] < dp[j] + 1) // Found a longer subsequence ending at i
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // Reset count to count[j] because we found a new LIS ending at i
                    }
                    else if (dp[i] == dp[j] + 1) // Found another LIS of the same length at i
                    {
                        count[i] += count[j]; // Add the number of ways we can form an LIS of this length
                    }
                }
            }

            // Update the maximum LIS length and the count of such sequences
            if (dp[i] > mx)
            {
                mx = dp[i];
                cnt = count[i]; // Reset cnt to the count of LIS ending at i with max length
            }
            else if (dp[i] == mx)
            {
                cnt += count[i]; // Add count of LISs of length mx
            }
        }

        return cnt;
    }
};
