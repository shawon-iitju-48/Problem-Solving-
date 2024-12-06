/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution
{
public:
    vector<string> generate(int j, string &digits, unordered_map<char, string> &mp)
    {
        vector<string> v, temp;
        if (j == digits.size() - 1)
        {
            for (int k = 0; k < mp[digits[j]].size(); k++)
                temp.push_back(string(1, mp[digits[j]][k]));
            return temp;
        }

        v = generate(j + 1, digits, mp);
        for (int k = 0; k < mp[digits[j]].size(); k++)
        {
            for (int l = 0; l < v.size(); l++)
                temp.push_back(mp[digits[j]][k] + v[l]);
        }
        return temp;
    }
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        return generate(0, digits, mp);
    }
};
// @lc code=end
