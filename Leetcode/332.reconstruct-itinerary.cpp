/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &path)
    {
        while (adj[i].size() > 0)
        {
            int lastindex = adj[i].size() - 1, x = adj[i][lastindex];
            adj[i].pop_back();
            dfs(x, adj, path);
        }
        path.push_back(i);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        set<string> st;
        for (int i = 0; i < tickets.size(); i++)
        {
            st.insert(tickets[i][0]);
            st.insert(tickets[i][1]);
        }
        unordered_map<string, int> mp;
        unordered_map<int, string> revmp;
        int index = 0;
        for (auto it = st.begin(); it != st.end(); it++)
        {
            revmp[index] = *it;
            mp[*it] = index;
            index++;
        }
        int n = st.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < tickets.size(); i++)
            adj[mp[tickets[i][0]]].push_back(mp[tickets[i][1]]);
        for (int i = 0; i < n; i++)
            sort(adj[i].begin(), adj[i].end(), greater<int>());
        vector<int> path;
        dfs(mp["JFK"], adj, path);
        vector<string> ans;
        for (int i = path.size() - 1; i >= 0; i--)
            ans.push_back(revmp[path[i]]);
        return ans;
    }
};
// @lc code=end
