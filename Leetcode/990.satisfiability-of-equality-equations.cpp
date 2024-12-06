/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
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
    void do_union(int i, int j, vector<int> &parent, vector<int> &rank)
    {
        int parenti = find_papa(i, parent), parentj = find_papa(j, parent);
        if (parenti != parentj)
        {
            if (rank[parenti] > rank[parentj])
                parent[parentj] = parenti;
            else if (rank[parentj] > rank[parenti])
                parent[parenti] = parentj;
            else
            {
                parent[parentj] = parenti;
                rank[parenti]++;
            }
        }
    }
    bool equationsPossible(vector<string> &equations)
    {
        vector<int> parent(26, 0), rank(26, 0);
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        for (int i = 0; i < equations.size(); i++)
        {
            if (equations[i][1] == '=')
            {
                int x = equations[i][0], y = equations[i][3];
                x = x % 97, y = y % 97;
                do_union(x, y, parent, rank);
            }
        }
        for (int i = 0; i < equations.size(); i++)
        {
            if (equations[i][1] == '!')
            {
                int x = equations[i][0], y = equations[i][3];
                x = x % 97, y = y % 97;
                if (find_papa(x, parent) == find_papa(y, parent))
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
