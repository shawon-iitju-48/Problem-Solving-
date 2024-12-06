/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<float> time;
        vector<pair<int, int>> v;
        for (int i = 0; i < position.size(); i++)
            v.push_back(make_pair(position[i], speed[i]));
        sort(v.begin(), v.end());
        for (int i = 0; i < position.size(); i++)
        {
            int dis = target - v[i].first;
            float t = dis * 1.0 / v[i].second;
            time.push_back(t);
        }
        stack<float>stk;
        stk.push(time[time.size()-1]);
        int cnt=1;
        for(int i=time.size()-2;i>=0;i--)
        {
            if(time[i]>stk.top())
            {
                cnt++;
                stk.push(time[i]);
            }
        }
        return cnt;
    }
};
// @lc code=end
