/*
 * @lc app=leetcode id=2959 lang=cpp
 *
 * [2959] Number of Possible Sets of Closing Branches
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets;
    void generateSubsets(int i, vector<int> content, vector<int> &v)
    {
        if (i >= v.size())
        {
            subsets.push_back(content);
            return;
        }

        generateSubsets(i + 1, content, v);
        content.push_back(v[i]);
        generateSubsets(i + 1, content, v);
    }
    bool check(int n, vector<int> subset, int &maxDistance, vector<vector<int>> &roads)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        vector<bool> vis(n, false);
        for (int i = 0; i < subset.size(); i++)
            vis[subset[i]] = true;

        for (auto &road : roads)
        {
            if (vis[road[0]] and vis[road[1]])
            {
                dist[road[0]][road[1]] = min(road[2], dist[road[0]][road[1]]);
                dist[road[1]][road[0]] = min(road[2], dist[road[1]][road[0]]);
            }
        }
        for (int k = 0; k < n; k++)
        {
            if (!vis[k])
                continue;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                        continue;
                    if (dist[i][k] != INT_MAX and dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j and vis[i] and vis[j] and dist[i][j] > maxDistance)
                    return false;
            }
        }
        return true;
    }
    int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
            v.push_back(i);
        generateSubsets(0, {}, v);

        int cnt = 0;
        for (auto &subset : subsets)
        {
            if (check(n, subset, maxDistance, roads))
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end
