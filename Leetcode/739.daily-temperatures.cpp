/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> stk;
        vector<int> ans;
        ans.resize(temperatures.size(), 0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            if (temperatures[i - 1] < temperatures[i])
            {
                ans[i - 1] = 1;
                while (!stk.empty())
                {
                    if (temperatures[i] > temperatures[stk.top()])
                    {
                        ans[stk.top()] = i - stk.top();
                        stk.pop();
                    }
                    else
                        break;
                }
            }
            else
                stk.push(i - 1);
        }
        return ans;
    }
};
// @lc code=end
