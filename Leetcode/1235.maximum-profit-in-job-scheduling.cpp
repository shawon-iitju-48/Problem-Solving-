/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution
{
public:
    int job(int i, vector<vector<int>> &info, vector<int> &next, vector<int> &dp)
    {
        if (i >= info.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int skip = job(i + 1, info, next, dp);
        int take = info[i][2] + job(next[i], info, next, dp);

        return dp[i] = max(skip, take);
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> v;
        vector<int> dp(n, -1);

        for (int i = 0; i < n; i++)
            v.push_back({startTime[i], endTime[i], profit[i]});

        sort(begin(v), end(v));

        vector<int> nextJob(n, n + 1);

        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(begin(v), end(v), vector<int>{v[i][1], 0, 0},
                                  [](const vector<int> &a, const vector<int> &b)
                                  {
                                      return a[0] < b[0];
                                  });
            if (it != v.end())
                nextJob[i] = it - v.begin();
        }

        return job(0, v, nextJob, dp);
    }
};
// @lc code=end
