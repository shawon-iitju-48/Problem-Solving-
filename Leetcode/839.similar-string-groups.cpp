/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 */

// @lc code=start
class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int size)
    {
        parent.resize(size);
        rank.resize(size, 0);
        iota(begin(parent), end(parent), 0);
    }
    int find_papa(int i)
    {
        if (parent[i] != i)
            parent[i] = find_papa(parent[i]);
        return parent[i];
    }

    void do_union(int i, int j)
    {
        int pi = find_papa(i);
        int pj = find_papa(j);

        if (pi != pj)
        {
            if (rank[pi] > rank[pj])
                parent[pj] = pi;
            else if (rank[pi] < rank[pj])
                parent[pi] = pj;
            else
            {
                parent[pj] = pi;
                rank[pi]++;
            }
        }
    }
};

class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cnt = 0;
                for (int k = 0; k < strs[i].size(); k++)
                {
                    if (strs[i][k] != strs[j][k])
                        cnt++;
                }
                if (cnt <= 2)
                    dsu.do_union(i, j);
            }
        }
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++)
            count[dsu.find_papa(i)]++;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (count[i] > 0)
                cnt++;
        return cnt;
    }
};
// @lc code=end
