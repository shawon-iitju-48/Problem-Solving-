/*
 * @lc app=leetcode id=1575 lang=cpp
 *
 * [1575] Count All Possible Routes
 */

// @lc code=start
class Solution
{
public:
    int dp[101][2001], MOD = 1e9 + 7;
    int solve(int curr, int curr_fuel, int &des, int &fuel, vector<int> &locations)
    {
        if (dp[curr][curr_fuel] != -1)
            return dp[curr][curr_fuel];

        int sum = (curr == des) ? 1 : 0, need;
        for (int i = 0; i < locations.size(); i++)
        {
            need = curr_fuel + abs(locations[curr] - locations[i]);
            if (curr != i and need <= fuel)
                sum = (sum + solve(i, need, des, fuel, locations)) % MOD;
        }
        return dp[curr][curr_fuel] = sum;
    }
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        memset(dp, -1, sizeof(dp));
        return solve(start, 0, finish, fuel, locations);
    }
};
// @lc code=end
