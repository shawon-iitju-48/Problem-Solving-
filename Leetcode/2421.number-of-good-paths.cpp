/*
 * @lc app=leetcode id=2421 lang=cpp
 *
 * [2421] Number of Good Paths
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
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges)
    {
        int n = vals.size();
        DSU dsu(n);

        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[vals[i]].push_back(i);

        vector<bool> active(n, false);
        int res = n;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            vector<int> v = it->second;
            for (int i = 0; i < v.size(); i++)
            {
                for (auto &j : adj[v[i]])
                {
                    if (active[j])
                        dsu.do_union(v[i], j);
                }
                active[v[i]] = true;
            }
            unordered_map<int, int> cnt;
            for (int i = 0; i < v.size(); i++)
                cnt[dsu.find_papa(v[i])]++;
            for (auto ot = cnt.begin(); ot != cnt.end(); ot++)
            {
                int x = ot->second;
                x = (x * (x - 1)) / 2;
                res += x;
            }
        }
        return res;
    }
};
// @lc code=end
