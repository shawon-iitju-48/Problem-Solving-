/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        for (int col = 0; col < strs[0].size(); col++)
        {
            char ch = strs[0][col];
            for (int row = 0; row < strs.size(); row++)
            {
                if (strs[row][col] != ch)
                    return ans;
            }
            ans += ch;
        }
        return ans;
    }
};
// @lc code=end
