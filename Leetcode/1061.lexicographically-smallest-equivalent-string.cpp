/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

// @lc code=start
class Solution
{
public:
    int find_papa(int i, vector<int> &parent)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find_papa(parent[i], parent);
    }
    void do_union(int i, int j, vector<int> &parent)
    {
        int pi = find_papa(i, parent);
        int pj = find_papa(j, parent);
        if (pi != pj)
        {
            if (pi < pj)
                parent[pj] = pi;
            else
                parent[pi] = pj;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        vector<int> parent(26);
        iota(parent.begin(), parent.end(), 0);
        int x, y;

        for (int i = 0; i < s1.size(); i++)
        {
            x = s1[i] - 'a', y = s2[i] - 'a';
            do_union(x, y, parent);
        }
        string s = "";
        for (int i = 0; i < baseStr.size(); i++)
        {
            x = find_papa(baseStr[i] - 'a', parent);
            char ch = x + 'a';
            s += ch;
        }
        return s;
    }
};
// @lc code=end
