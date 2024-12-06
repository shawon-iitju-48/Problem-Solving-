/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
class Solution
{
public:
    int count(int ri, int ki, int n)
    {
        int dist = abs(ri - ki);
        int wrap = n - dist;
        return min(dist, wrap);
    }
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size();
        unordered_map<char, vector<int>> adj;
        for (int i = 0; i < n; i++)
            adj[ring[i]].push_back(i);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0});
        set<pair<int, int>> st;
        int step;
        while (!q.empty())
        {
            step = q.top()[0];
            int ri = q.top()[1], k = q.top()[2];
            q.pop();
            if (k == key.size())
                break;
            if (st.find({ri, k}) == st.end())
            {
                st.insert({ri, k});
                for (auto &i : adj[key[k]])
                    q.push({count(ri, i, n) + step, i, k + 1});
            }
        }
        return step + key.size();
    }
};
// @lc code=end
