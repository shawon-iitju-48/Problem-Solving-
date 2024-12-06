/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        int groupSize = routes.size();
        vector<bool> visitedGroup(groupSize, false);
        unordered_map<int, vector<int>> groupmap;
        for (int i = 0; i < groupSize; i++)
        {
            for (auto &j : routes[i])
                groupmap[j].push_back(i);
        }
        queue<pair<int, int>> q;
        if (source == target)
            return 0;
        if (groupmap.find(source) == groupmap.end() or groupmap.find(target) == groupmap.end())
            return -1;
        for (auto &g : groupmap[source])
        {
            q.push({g, 1});
            visitedGroup[g] = true;
        }
        while (!q.empty())
        {
            int g = q.front().first, buscount = q.front().second;
            q.pop();
            for (auto &busstop : routes[g])
            {
                if (busstop == target)
                    return buscount;
                for (auto &d : groupmap[busstop])
                {
                    if (!visitedGroup[d])
                    {
                        q.push({d, buscount + 1});
                        visitedGroup[d] = true;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
