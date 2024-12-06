/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalgas = 0, totalcost = 0;
        for (int i = 0; i < gas.size(); i++)
            totalgas += gas[i];
        for (int i = 0; i < cost.size(); i++)
            totalcost += cost[i];
        if (totalgas < totalcost)
            return -1;
        vector<int> v;
        for (int i = 0; i < cost.size(); i++)
            v.push_back(gas[i] - cost[i]);
        int flag = -1, sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
            if (sum >= 0 and flag == -1)
                flag = i;
            if (sum < 0)
            {
                flag = -1;
                sum = 0;
            }
        }
        return flag;
    }
};
// @lc code=end
