/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
 */

// @lc code=start
class Solution
{
public:
    void dfs(int dist, int node, vector<int> &edges, vector<bool> &visited, unordered_map<int, int> &mp)
    {
        visited[node] = true;
        mp[node] = dist;

        if (edges[node] != -1 and !visited[edges[node]])
            dfs(dist + 1, edges[node], edges, visited, mp);

        visited[node] = false;
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        unordered_map<int, int> mp1, mp2;
        vector<bool> visited(edges.size(), false);
        dfs(0, node1, edges, visited, mp1);
        dfs(0, node2, edges, visited, mp2);
        int mn = INT_MAX, index = -1;
        for (auto it = mp1.begin(); it != mp1.end(); it++)
        {
            if (mp2.find(it->first) != mp2.end())
            {
                int x = max(it->second, mp2[it->first]);
                if (x < mn)
                {
                    mn = x;
                    index = it->first;
                }
                else if (x == mn and it->first < index)
                    index = it->first;
            }
        }
        return index;
    }
};
// @lc code=end
