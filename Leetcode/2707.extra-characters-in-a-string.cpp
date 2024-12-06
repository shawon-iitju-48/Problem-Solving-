/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
class Solution
{
public:
    unordered_set<string> st;
    int dp[50];
    int solve(int idx, string &s)
    {
        if (idx >= s.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int mn = 1 + solve(idx + 1, s);
        string temp = "";
        for (int i = idx; i < s.size(); i++)
        {
            temp += s[i];
            if (st.count(temp))
                mn = min(mn, solve(i + 1, s));
            else
                mn = min(mn, i - idx + 1 + solve(i + 1, s));
        }
        return dp[idx] = mn;
    }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        for (auto &str : dictionary)
            st.insert(str);
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};
// @lc code=end
