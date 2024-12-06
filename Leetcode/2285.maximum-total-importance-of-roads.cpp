/*
 * @lc app=leetcode id=2285 lang=cpp
 *
 * [2285] Maximum Total Importance of Roads
 */

// @lc code=start
class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<long long> indegree(n, 0);
        for (auto &road : roads)
        {
            indegree[road[0]]++;
            indegree[road[1]]++;
        }
        multimap<long long, long long> mp;
        for (int i = 0; i < n; i++)
            mp.insert({indegree[i], i});

        long long x = n;
        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            indegree[it->second] = x;
            x--;
        }

        long long sum = 0;
        for (auto &road : roads)
            sum += indegree[road[0]] + indegree[road[1]];

        return sum;
    }
};
// @lc code=end
