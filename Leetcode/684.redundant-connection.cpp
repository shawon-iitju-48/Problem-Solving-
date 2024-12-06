/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
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
    bool do_union(int i, int j, vector<int> &parent, vector<int> &rank)
    {
        int parenti = find_papa(i, parent), parentj = find_papa(j, parent);
        if (parenti != parentj)
        {
            if (rank[parenti] > rank[parentj])
                parent[parentj] = parenti;
            else if (rank[parenti] < rank[parentj])
                parent[parenti] = parentj;
            else
            {
                parent[parentj] = parenti;
                rank[parenti]++;
            }
            return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1, 0), rank(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++)
            if (do_union(edges[i][0], edges[i][1], parent, rank) == false)
                return edges[i];
        return {};
    }
};
// @lc code=end
