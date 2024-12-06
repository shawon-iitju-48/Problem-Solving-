/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> ans;
    bool check(string &xd)
    {
        int start = 0, end = xd.size() - 1;
        while (start <= end)
        {
            if (xd[start] != xd[end])
                return false;
            start++, end--;
        }
        return true;
    }
    void generate(int j, vector<string> v, string &s)
    {
        if (j >= s.size())
        {
            ans.push_back(v);
            return;
        }
        string temp = "";
        for (int i = j; i < s.size(); i++)
        {
            temp += s[i];
            if (check(temp))
            {
                vector<string> t = v;
                t.push_back(temp);
                generate(i + 1, t, s);
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        generate(0, {}, s);
        return ans;
    }
};
// @lc code=end
