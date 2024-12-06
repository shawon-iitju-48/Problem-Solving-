/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> pq;
        int dist;
        for (int i = 0; i < points.size(); i++)
        {
            dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            if (pq.size() < k)
                pq.push({dist, {points[i][0], points[i][1]}});
            else if (pq.top().first > dist)
            {
                pq.pop();
                pq.push({dist, {points[i][0], points[i][1]}});
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
