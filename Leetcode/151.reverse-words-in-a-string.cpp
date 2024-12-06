/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        s.push_back(' ');

        int start = -1, flag = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' and start != -1)
            {
                reverse(s.begin() + start, s.begin() + i);
                start = -1;
            }
            else if (s[i] != ' ' and start == -1)
                start = i;
        }
        start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                flag = 1;
                s[start++] = s[i];
            }
            else if (s[i] == ' ' and flag == 1)
            {
                flag = 0;
                s[start++] = ' ';
            }
        }
        s.erase(start - 1);
        return s;
    }
};
// @lc code=end
