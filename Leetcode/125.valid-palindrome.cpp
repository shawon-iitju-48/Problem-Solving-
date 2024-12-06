/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        vector<char> v;
        for (int i = 0; i < s.size(); i++)
            if ((s[i] >= 'a' and s[i] <= 'z') || (s[i] >= 'A' and s[i] <= 'Z') || (s[i] >= '0' and s[i] <= '9'))
                v.push_back(tolower(s[i]));
        int front = 0, back = v.size() - 1, flag = 0;
        while (front < back)
        {
            if (v[front] == v[back])
            {
                front++;
                back--;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return true;
        else
            return false;
    }
};
// @lc code=end
