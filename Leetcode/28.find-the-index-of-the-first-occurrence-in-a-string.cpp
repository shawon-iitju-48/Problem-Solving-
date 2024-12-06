/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = needle.size(), ln = 0, j = 1, i;
        vector<int> lps(n, 0);
        while (j < n)
        {
            if (needle[ln] == needle[j])
            {
                ln++;
                lps[j] = ln;
                j++;
            }
            else
            {
                if (ln != 0)
                    ln = lps[ln - 1];
                else
                    lps[j++] = 0;
            }
        }
        i = 0, j = 0;
        while (i < haystack.size())
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else if (j > 0)
                j = lps[j - 1];
            else
                i++;

            if (j == needle.size())
                return i - j;
        }
        return -1;
    }
};
// @lc code=end
