/*
 * @lc app=leetcode id=1489 lang=cpp
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
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

    void do_union(int pi, int pj)
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
};

class Solution
{
public:
    int find_mst(int &n, vector<vector<int>> &edges, vector<int> v, int flag)
    {
        DSU dsu(n);
        int sum = 0;
        if (flag == 1)
        {
            sum += v[2];
            dsu.do_union(v[0], v[1]);
        }
        for (int i = 0; i < edges.size(); i++)
        {
            if (flag == 0 and edges[i][0] == v[0] and edges[i][1] == v[1])
                continue;

            int pi = dsu.find_papa(edges[i][0]);
            int pj = dsu.find_papa(edges[i][1]);
            if (pi != pj)
            {
                sum += edges[i][2];
                dsu.do_union(pi, pj);
            }
        }
        int papa = dsu.find_papa(0);
        for (int i = 1; i < n; i++)
        {
            if (dsu.find_papa(i) != papa)
                return -1;
        }
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        sort(begin(edges), end(edges), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        int mst = find_mst(n, edges, {}, -1);
        vector<vector<int>> ans(2);

        for (int i = 0; i < edges.size(); i++)
        {
            int x = find_mst(n, edges, edges[i], 0);
            if (x > mst or x == -1)
                ans[0].push_back(edges[i][3]);
            else
            {
                x = find_mst(n, edges, edges[i], 1);
                if (x == mst)
                    ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};
// @lc code=end
