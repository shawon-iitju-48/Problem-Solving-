/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int mx = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
                mp[s[i]]++;
            if (i >= k and mp.count(s[i - k]) > 0)
                mp[s[i - k]] = max(0, mp[s[i - k]] - 1);
            int sum = 0;
            for (auto it = mp.begin(); it != mp.end(); it++)
                sum += it->second;
            mx = max(mx, sum);
        }
        return mx;
    }
};
// @lc code=end
