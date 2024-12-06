/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int solve(int idx, vector<int> &stoneValue, vector<int> &dp)
    {
        if (idx >= stoneValue.size())
            return 0;

        if (dp[idx] != INT_MIN)
            return dp[idx];

        int res = INT_MIN, sum = 0;

        for (int i = idx; i < idx + 3 && i < stoneValue.size(); i++)
        {
            sum += stoneValue[i];
            res = max(res, sum - solve(i + 1, stoneValue, dp));
        }

        return dp[idx] = res;
    }

    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);

        int aliceScore = solve(0, stoneValue, dp);

        if (aliceScore == 0)
            return "Tie";

        if (aliceScore > 0)
            return "Alice";

        return "Bob";
    }
};
// @lc code=end
