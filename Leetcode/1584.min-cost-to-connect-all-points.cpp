/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
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
    void do_union(int pi, int pj, vector<int> &parent, vector<int> &rank)
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
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<vector<int>> v;
        int V = points.size();
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                v.push_back({dist, i, j});
            }
        }
        sort(v.begin(), v.end());

        vector<int> parent(V), rank(V, 0);
        iota(parent.begin(), parent.end(), 0);

        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int pi = find_papa(v[i][1], parent), pj = find_papa(v[i][2], parent);
            if (pi != pj)
            {
                do_union(pi, pj, parent, rank);
                sum += v[i][0];
            }
        }
        return sum;
    }
};
// @lc code=end
