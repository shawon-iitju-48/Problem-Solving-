/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string str = "#";
        for (int i = 0; i < s.size(); i++)
        {
            str += s[i];
            str += "#";
        }

        int maxLen = 0, startfrom = 0, l = 0, r = 0, n = str.size(), k;
        vector<int> p(n, 0);

        for (int i = 1; i < n; i++)
        {
            if (i > r)
                k = 0;
            else
            {
                int j = l + r - i;
                if (j - p[j] > l)
                {
                    p[i] = p[j];
                    continue;
                }
                else
                    k = r - i;
            }

            while (i - k >= 0 and i + k < n and str[i - k] == str[i + k])
                k++;
            k--;

            if (i + k > r)
            {
                r = i + k;
                l = i - k;
            }

            p[i] = k;
            if (p[i] > maxLen)
            {
                maxLen = p[i];
                startfrom = (l + 1) / 2;
            }
        }
        return s.substr(startfrom, maxLen);
    }
};
// @lc code=end