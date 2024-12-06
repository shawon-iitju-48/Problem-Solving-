/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 */

// @lc code=start
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int solve(int idx, string &s, int &k, vector<int> &dp)
    {
        if (idx >= s.size())
            return 1;

        if (s[idx] == '0')
            return 0;

        if (dp[idx] != -1)
            return dp[idx];
        int currentNumber = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            currentNumber = currentNumber * 10 + (s[i] - '0');
            if (currentNumber <= k)
                cnt = (cnt + solve(i + 1, s, k, dp)) % MOD;
        }
        return dp[idx] = cnt;
    }
    int numberOfArrays(string s, int k)
    {
        vector<int> dp(s.size(), -1);
        return solve(0, s, k, dp);
    }
};
// @lc code=end
