/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st;
        queue<pair<string, int>> q;
        string temp, tt;
        int level;
        for (int i = 0; i < wordList.size(); i++)
            st.insert(wordList[i]);

        q.push({beginWord, 1});
        while (!q.empty())
        {
            temp = q.front().first, level = q.front().second;
            q.pop();
            if (temp == endWord)
                return level;
            for (int i = 0; i < temp.size(); i++)
            {
                tt = temp;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    tt[i] = ch;
                    if (st.find(tt) != st.end())
                    {
                        st.erase(tt);
                        q.push({tt, level + 1});
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
