/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution
{
public:
    int n, dp[1005][1005];
    int solve(int previousCopied, int currLen)
    {
        if (currLen >= n)
            return currLen == n ? 0 : INT_MAX;

        if (dp[previousCopied][currLen] != -1)
            return dp[previousCopied][currLen];

        int copy = INT_MAX, paste = INT_MAX;

        if (previousCopied < currLen)
            copy = solve(currLen, currLen);

        if (previousCopied > 0)
            paste = solve(previousCopied, previousCopied + currLen);

        copy = copy == INT_MAX ? copy : 1 + copy;
        paste = paste == INT_MAX ? paste : 1 + paste;

        return dp[previousCopied][currLen] = min(copy, paste);
    }
    int minSteps(int nn)
    {
        n = nn;
        memset(dp, -1, sizeof(dp));
        return solve(0, 1);
    }
};
// @lc code=end
