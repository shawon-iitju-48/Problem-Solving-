/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int endg = g.size() - 1, ends = s.size() - 1, cnt = 0;
        while (endg >= 0 and ends >= 0)
        {
            if (s[ends] >= g[endg])
            {
                cnt++;
                ends--;
                endg--;
            }
            else
                endg--;
        }
        return cnt;
    }
};
// @lc code=end
