class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        vector<int> dp(26, 0);
        int mx = 1;
        for (int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 'a', tempMax = 0;
            for (int j = max(0, x - k); j <= min(25, x + k); j++)
                tempMax = max(tempMax, 1 + dp[j]);

            dp[x] = tempMax;
            mx = max(mx, dp[x]);
        }
        return mx;
    }
};
