/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> mp;
        int index = 0;
        for (auto &acc : accounts)
            for (int i = 1; i < acc.size(); i++)
                if (mp.find(acc[i]) == mp.end())
                    mp[acc[i]] = index++;

        vector<vector<int>> adj(accounts.size());
        for (int j = 0; j < accounts.size(); j++)
            for (int i = 1; i < accounts[j].size(); i++)
                adj[j].push_back(mp[accounts[j][i]]);

        DSU dsu(index);
        for (auto &a : adj)
            for (int i = 1; i < a.size(); i++)
                dsu.do_union(a[i], a[i - 1]);

        unordered_map<int, pair<string, set<string>>> tempans;

        for (auto &acc : accounts)
        {
            int parent = dsu.find_papa(mp[acc[1]]);
            tempans[parent].first = acc[0];
            tempans[parent].second.insert(acc.begin() + 1, acc.end());
        }
        vector<vector<string>> ans(tempans.size());
        int d = 0;
        for (const auto &it : tempans)
        {
            ans[d].push_back(it.second.first);
            ans[d].insert(ans[d].end(), it.second.second.begin(), it.second.second.end());
            d++;
        }
        return ans;
    }
};
// @lc code=end
