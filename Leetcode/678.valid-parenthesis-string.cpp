/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution
{
public:
    bool checkValidString(string s)
    {
        int minopen = 0, maxopen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                minopen++;
                maxopen++;
            }
            else if (s[i] == '*')
            {
                maxopen++;
                minopen--;
            }
            else
            {
                maxopen--;
                minopen--;
            }
            if (maxopen < 0)
                return false;
            minopen = max(0, minopen);
        }

        if (minopen == 0)
            return true;
        else
            return false;
    }
};
// @lc code=end
