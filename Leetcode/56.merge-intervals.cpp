/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (ans[ans.size() - 1][1] < intervals[i][0])
                ans.push_back(intervals[i]);
            else
            {
                if (ans[ans.size() - 1][1] < intervals[i][1])
                    ans[ans.size() - 1][1] = intervals[i][1];
            }
        }
        return ans;
    }
};
// @lc code=end
