/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
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
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1])
                    do_union(i, j, parent, rank);
            }
        }

        unordered_set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(find_papa(i, parent));

        return n - st.size();
    }
};
// @lc code=end
