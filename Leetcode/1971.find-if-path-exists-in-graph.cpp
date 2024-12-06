/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
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
        int pi = find_papa(i, parent);
        int pj = find_papa(j, parent);
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
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < edges.size(); i++)
            do_union(edges[i][0], edges[i][1], parent, rank);
        if (find_papa(source, parent) != find_papa(destination, parent))
            return false;
        return true;
    }
};
// @lc code=end
