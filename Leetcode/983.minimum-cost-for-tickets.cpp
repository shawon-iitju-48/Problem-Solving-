/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution
{
public:
    int solve(int i, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        if (i >= days.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int one = INT_MAX, seven = INT_MAX, thirty = INT_MAX;

        auto it = upper_bound(begin(days), end(days), days[i]);
        int onei = it - days.begin();

        it = upper_bound(begin(days), end(days), days[i] + 6);
        int seveni = it - days.begin();

        it = upper_bound(begin(days), end(days), days[i] + 29);
        int thirtyi = it - days.begin();

        one = costs[0] + solve(onei, days, costs, dp);
        seven = costs[1] + solve(seveni, days, costs, dp);
        thirty = costs[2] + solve(thirtyi, days, costs, dp);

        return dp[i] = min({one, seven, thirty});
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size(), -1);
        return solve(0, days, costs, dp);
    }
};
// @lc code=end
