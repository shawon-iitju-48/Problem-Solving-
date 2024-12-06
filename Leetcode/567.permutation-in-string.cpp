/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int window = s1.size();
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < window; i++)
            freq1[s1[i] - 'a']++;

        for (int i = 0; i < s2.size(); i++)
        {
            freq2[s2[i] - 'a']++;
            if (i >= window - 1)
            {
                int flag = 0;
                for (int d = 0; d < 26; d++)
                {
                    if (freq1[d] != freq2[d])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    return true;
                freq2[s2[i-window + 1] - 'a']--;
            }
        }
        return false;
    }
};
// @lc code=end
