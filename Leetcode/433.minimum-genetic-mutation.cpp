/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        queue<pair<string, int>> q;
        unordered_set<string> st;
        for (int i = 0; i < bank.size(); i++)
            st.insert(bank[i]);
        q.push({startGene, 0});

        vector<char> dict = {'A', 'C', 'G', 'T'};
        while (!q.empty())
        {
            string temp = q.front().first;
            int level = q.front().second;
            q.pop();
            if (temp == endGene)
                return level;
            for (int j = 0; j < 8; j++)
            {
                char ch = temp[j];
                for (int i = 0; i < 4; i++)
                {
                    temp[j] = dict[i];
                    if (st.find(temp) != st.end())
                    {
                        st.erase(temp);
                        q.push({temp, level + 1});
                    }
                }
                temp[j] = ch;
            }
        }
        return -1;
    }
};
// @lc code=end
