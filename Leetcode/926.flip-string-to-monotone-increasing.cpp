/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */

// @lc code=start
class Solution
{
public:
    int solve(int i, string &s, vector<int> &count)
    {
        if (i >= s.size())
            return 0;

        int take = 0, skip = 0, n = s.size();

        skip = n - i - count[i];

        if (s[i] == '0')
            take = solve(i + 1, s, count);
        else
            take = 1 + solve(i + 1, s, count);

        return min(take, skip);
    }
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();
        vector<int> count(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            if (i < n - 1)
                count[i] = count[i + 1];
            if (s[i] == '1')
                count[i]++;
        }
        return solve(0, s, count);
    }
};
// @lc code=end
