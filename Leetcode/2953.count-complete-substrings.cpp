/*
 * @lc app=leetcode id=2953 lang=cpp
 *
 * [2953] Count Complete Substrings
 */

// @lc code=start
class Solution
{
public:
    int countCompleteSubstrings(string word, int k)
    {
        int cnt = 0;
        for (int len = 1; len <= 26; len++)
        {
            int windowSize = k * len, i = 0, y = -1, x;
            vector<int> count(26, 0);
            for (int j = 0; j < word.size(); j++)
            {
                x = word[j] - 'a';
                if (j > 0)
                    y = word[j - 1] - 'a';

                if (y >= 0 && abs(x - y) > 2)
                {
                    while (i < j)
                    {
                        count[word[i] - 'a']--;
                        i++;
                    }
                }
                count[x]++;
                if (j - i + 1 >= windowSize)
                {
                    int flag = 0;
                    for (int d = 0; d < 26; d++)
                    {
                        if (count[d] != 0 && count[d] != k)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0)
                        cnt++;
                    count[word[i] - 'a']--;
                    i++;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
