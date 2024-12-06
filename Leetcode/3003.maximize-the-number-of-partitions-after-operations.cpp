/*
 * @lc app=leetcode id=3003 lang=cpp
 *
 * [3003] Maximize the Number of Partitions After Operations
 */

// @lc code=start
class Solution
{
public:
    int k;
    unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;

    int solve(int i, int canChange, int freqState, string &s)
    {
        if (i >= s.size())
            return 0;

        if (dp[i][canChange].count(freqState))
            return dp[i][canChange][freqState];

        int curr = s[i] - 'a', mx = 0;
        int newstate = freqState | (1 << curr);
        int freq = __builtin_popcount(freqState);

        if (freqState != newstate and 1 + freq > k)
            mx = max(mx, 1 + solve(i + 1, canChange, 1 << curr, s));
        else
            mx = max(mx, solve(i + 1, canChange, newstate, s));

        if (canChange == 1)
        {
            for (int d = 0; d < 26; d++)
            {
                if (d != curr and ((freqState & (1 << d)) == 0))
                {
                    newstate = freqState | (1 << d);
                    if (freqState != newstate and 1 + freq > k)
                        mx = max(mx, 1 + solve(i + 1, 0, 1 << d, s));
                    else
                        mx = max(mx, solve(i + 1, 0, newstate, s));
                }
            }
        }
        return dp[i][canChange][freqState] = mx;
    }
    int maxPartitionsAfterOperations(string s, int kk)
    {
        k = kk;
        return 1 + solve(0, 1, 0, s);
    }
};
// @lc code=end