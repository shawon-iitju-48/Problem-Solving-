/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
class Solution
{
public:
    int dp[1001][1001];
    const int MOD = 1e9 + 7;
    int solve(int idx, int ti, vector<vector<long long>> &freq, string &target)
    {
        if (ti >= target.size())
            return 1;

        if (idx >= freq.size())
            return 0;

        if (dp[idx][ti] != -1)
            return dp[idx][ti];

        int cnt = solve(idx + 1, ti, freq, target);

        if (freq[idx][target[ti] - 'a'])
            cnt = (cnt + (freq[idx][target[ti] - 'a'] * (long long)solve(idx + 1, ti + 1, freq, target)) % MOD) % MOD;

        return dp[idx][ti] = cnt;
    }
    int numWays(vector<string> &words, string target)
    {
        memset(dp, -1, sizeof(dp));
        vector<vector<long long>> freq(words[0].size(), vector<long long>(26, 0));
        for (int i = 0; i < words[0].size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
                freq[i][words[j][i] - 'a']++;
        }
        return solve(0, 0, freq, target);
    }
};
// @lc code=end
