/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution
{
public:
    int check(int i, int j, string &s1, string &s2, string &s3, unordered_map<string, int> &dp)
    {
        string key = to_string(i) + to_string(j);
        int k = i + j;
        if (i >= s1.size() and j >= s2.size() and k >= s3.size())
            return 1;
        if (k >= s3.size())
            return 0;

        if (dp.find(key) != dp.end())
            return dp[key];
        if (s1[i] == s3[k] and check(i + 1, j, s1, s2, s3, dp) == 1)
            return dp[key] = 1;
        if (s2[j] == s3[k] and check(i, j + 1, s1, s2, s3, dp) == 1)
            return dp[key] = 1;
        return dp[key] = 0;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        unordered_map<string, int> dp;
        return check(0, 0, s1, s2, s3, dp);
    }
};
// @lc code=end
