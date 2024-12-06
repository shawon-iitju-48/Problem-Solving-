/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        vector<int> ord(26, -1);
        for (int i = 0; i < order.size(); i++)
            ord[(order[i] - 'a') % 97] = i;
        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                if (j >= words[i + 1].size())
                    return false;

                if (words[i][j] != words[i + 1][j])
                {
                    int x = (words[i][j] - 'a') % 97;
                    int y = (words[i + 1][j] - 'a') % 97;
                    if (ord[x] > ord[y])
                        return false;
                    break;
                }
            }
        }
        return true;
    }
};
// @lc code=end
