/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

// @lc code=start
class Solution
{
public:
    int solve(int curr_index, int curr_k, int &k, vector<vector<int>> &events, vector<vector<int>> &dp)
    {
        if (curr_index >= events.size() or curr_k == k)
            return 0;

        if (dp[curr_index][curr_k] != -1)
            return dp[curr_index][curr_k];
        int mx = solve(curr_index + 1, curr_k, k, events, dp), next = 0;
        int next_index = upper_bound(begin(events), end(events), events[curr_index][1],
                                     [](int value, const vector<int> &event)
                                     {
                                         return value < event[0];
                                     }) -
                         begin(events);

        if (next_index < events.size())
            next = solve(next_index, curr_k + 1, k, events, dp);

        return dp[curr_index][curr_k] = max(mx, events[curr_index][2] + next);
    }
    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(begin(events), end(events), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        vector<vector<int>> dp(events.size(), vector<int>(k, -1));
        return solve(0, 0, k, events, dp);
    }
};
// @lc code=end
