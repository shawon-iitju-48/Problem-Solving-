/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        int flag = 0;
        string word;
        vector<string> used;

        q.push({beginWord});

        while (!q.empty() && flag == 0)
        {
            int sz = q.size();
            for (int j = 0; j < sz; j++)
            {
                word = q.front().back();

                for (int i = 0; i < word.size(); i++)
                {
                    char cha = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[i] = ch;
                        if (st.find(word) != st.end())
                        {
                            used.push_back(word);
                            q.front().push_back(word);
                            if (word == endWord)
                            {
                                ans.push_back(q.front());
                                flag = 1;
                            }
                            else
                                q.push(q.front());
                            q.front().pop_back();
                        }
                    }
                    word[i] = cha;
                }
                q.pop();
            }
            for (int i = used.size() - 1; i >= 0; i--)
            {
                st.erase(used[i]);
                used.pop_back();
            }
        }
        return ans;
    }
};
// @lc code=end