/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, int> mp;
    unordered_map<string, bool> dp;

    bool wordsegment(int i, string temp, string &s)
    {
        string key = to_string(i) + "," + temp;

        if (i == s.size())
        {
            if (mp.find(temp) == mp.end() && !temp.empty())
                return false;
            else
                return true;
        }

        if (dp.find(key) != dp.end())
            return dp[key];

        temp = temp + s[i];

        if (mp.find(temp) != mp.end() && wordsegment(i + 1, "", s))
            return dp[key] = true;
        else if (wordsegment(i + 1, temp, s))
            return dp[key] = true;

        return dp[key] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (int i = 0; i < wordDict.size(); i++)
            mp[wordDict[i]] = 1;

        return wordsegment(0, "", s);
    }
};
// @lc code=end
