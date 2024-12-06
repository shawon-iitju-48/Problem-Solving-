/*
 * @lc app=leetcode id=1888 lang=cpp
 *
 * [1888] Minimum Number of Flips to Make the Binary String Alternating
 */

// @lc code=start
class Solution
{
public:
    int minFlips(string s)
    {
        int e0 = 0, e1 = 0, o0 = 0, o1 = 0, mn = INT_MAX, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '1')
                    e1++;
                else
                    e0++;
            }
            else
            {
                if (s[i] == '1')
                    o1++;
                else
                    o0++;
            }
        }
        mn = min(mn, min(e1 + o0, e0 + o1));
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] == '1')
                    e1--;
                else
                    e0--;

                if ((n - 1) % 2 == 0)
                {
                    if (s[i] == '1')
                        o1++;
                    else
                        o0++;
                }
                else
                {
                    if (s[i] == '1')
                        e1++;
                    else
                        e0++;
                }
            }
            else
            {
                if (s[i] == '1')
                    o1--;
                else
                    o0--;

                if ((n - 1) % 2 == 0)
                {
                    if (s[i] == '1')
                        e1++;
                    else
                        e0++;
                }
                else
                {
                    if (s[i] == '1')
                        o1++;
                    else
                        o0++;
                }
            }
            mn = min(mn, min(e1 + o0, e0 + o1));
        }
        return mn;
    }
};
// @lc code=end
