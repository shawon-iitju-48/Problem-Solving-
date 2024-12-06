/*
 * @lc app=leetcode id=2709 lang=cpp
 *
 * [2709] Greatest Common Divisor Traversal
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
    void doyourjob(int j, int n, unordered_map<int, int> &mp, DSU &dsu)
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (mp.count(i) > 0)
                    dsu.do_union(mp[i], j);
                else
                    mp[i] = j;
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 1)
        {
            if (mp.count(n) > 0)
                dsu.do_union(mp[n], j);
            else
                mp[n] = j;
        }
    }
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        DSU dsu(n);
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
            doyourjob(i, nums[i], mp, dsu);

        for (int i = 1; i < n; i++)
            if (dsu.find_papa(i) != dsu.find_papa(i - 1))
                return false;
        return true;
    }
};
// @lc code=end
