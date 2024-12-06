/*
 * @lc app=leetcode id=1964 lang=cpp
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
 */

// @lc code=start
class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> ans, lis;
        for (int i = 0; i < obstacles.size(); i++)
        {
            auto it = upper_bound(lis.begin(), lis.end(), obstacles[i]);
            if (it != lis.end())
            {
                int x = it - lis.begin();
                ans.push_back(x + 1);
                lis[x] = obstacles[i];
            }
            else
            {
                lis.push_back(obstacles[i]);
                ans.push_back(lis.size());
            }
        }
        return ans;
    }
};
// @lc code=end
