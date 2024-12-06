/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> fortxt(26, 0), forpat(26, 0);

        for (int i = 0; i < p.size(); i++)
            forpat[(p[i] - 'a') % 97]++;

        vector<int> ans;
        for (int i = 0; i < s.size(); i++)
        {
            fortxt[(s[i] - 'a') % 97]++;
            if (i >= p.size())
                fortxt[(s[i - p.size()] - 'a') % 97]--;
            int flag = 0;
            for (int j = 0; j < 26; j++)
            {
                if (fortxt[j] != forpat[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
// @lc code=end
