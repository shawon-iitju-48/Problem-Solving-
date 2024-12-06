/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1", temp;
        for (int i = 2; i <= n; i++)
        {
            temp = "";
            int cnt = 1, j;
            for (j = 1; j < s.size(); j++)
            {
                if (s[j] == s[j - 1])
                    cnt++;
                else
                {
                    temp += to_string(cnt) + s[j - 1];
                    cnt = 1;
                }
            }
            temp += to_string(cnt) + s[j - 1];
            s = temp;
        }
        return s;
    }
};
// @lc code=end
