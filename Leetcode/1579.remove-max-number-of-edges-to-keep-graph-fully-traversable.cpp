/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
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
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DSU dsu1(n + 1), dsu2(n + 1);

        int cnt = 0;
        sort(edges.begin(), edges.end(), greater<vector<int>>());
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i][0] == 3)
            {
                if (dsu1.find_papa(edges[i][1]) == dsu1.find_papa(edges[i][2]) and (dsu2.find_papa(edges[i][1]) == dsu2.find_papa(edges[i][2])))
                    cnt++;
                else
                {
                    dsu1.do_union(edges[i][1], edges[i][2]);
                    dsu2.do_union(edges[i][1], edges[i][2]);
                }
            }
            else if (edges[i][0] == 1)
            {
                if (dsu1.find_papa(edges[i][1]) == dsu1.find_papa(edges[i][2]))
                    cnt++;
                else
                    dsu1.do_union(edges[i][1], edges[i][2]);
            }
            else
            {
                if (dsu2.find_papa(edges[i][1]) == dsu2.find_papa(edges[i][2]))
                    cnt++;
                else
                    dsu2.do_union(edges[i][1], edges[i][2]);
            }
        }
        int first = dsu1.find_papa(1), second = dsu2.find_papa(1);
        for (int i = 2; i <= n; i++)
        {
            if (dsu1.find_papa(i) != first or dsu2.find_papa(i) != second)
                return -1;
        }
        return cnt;
    }
};
// @lc code=end
