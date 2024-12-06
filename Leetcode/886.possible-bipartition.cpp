/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
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
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> parent(n + 1), rank(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);

        vector<vector<int>> adj(n + 1);
        for (auto &dislike : dislikes)
        {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }

        for (int node = 1; node <= n; node++)
        {
            for (int neighbor : adj[node])
            {
                if (find_papa(node, parent) == find_papa(neighbor, parent))
                    return false;

                do_union(adj[node][0], neighbor, parent, rank);
            }
        }
        return true;
    }
};
// @lc code=end
