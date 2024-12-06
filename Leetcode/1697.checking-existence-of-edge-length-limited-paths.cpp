/*
 * @lc app=leetcode id=1697 lang=cpp
 *
 * [1697] Checking Existence of Edge Length Limited Paths
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        DSU dsu(n);
        sort(edgeList.begin(), edgeList.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        for (int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);

        sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        vector<bool> answer(queries.size(), 0);
        int j = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            while (j < edgeList.size() and edgeList[j][2] < queries[i][2])
            {
                dsu.do_union(edgeList[j][0], edgeList[j][1]);
                j++;
            }
            if (dsu.find_papa(queries[i][0]) == dsu.find_papa(queries[i][1]))
                answer[queries[i][3]] = true;
            else
                answer[queries[i][3]] = false;
        }
        return answer;
    }
};
// @lc code=end
