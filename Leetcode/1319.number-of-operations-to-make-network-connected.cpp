/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
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

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < (n - 1))
            return -1;
        vector<int> parent(n, 0), rank(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < connections.size(); i++)
            do_union(connections[i][0], connections[i][1], parent, rank);
        int cnt = -1;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                cnt++;
        return cnt;
    }
};
// @lc code=end
