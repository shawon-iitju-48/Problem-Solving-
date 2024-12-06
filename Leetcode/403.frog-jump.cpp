/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> mp;
    unordered_map<int, unordered_map<int, bool>> dp;
    bool solve(int i, int k, vector<int> &stone)
    {
        if (i == stone.size() - 1)
            return true;

        if (dp[i].count(k))
            return dp[i][k];

        if (k - 1 > 0 and mp.count(stone[i] + k - 1) and solve(mp[stone[i] + k - 1], k - 1, stone))
            return dp[i][k] = true;

        if (mp.count(stone[i] + k) and solve(mp[stone[i] + k], k, stone))
            return dp[i][k] = true;

        if (mp.count(stone[i] + k + 1) and solve(mp[stone[i] + k + 1], k + 1, stone))
            return dp[i][k] = true;

        return dp[i][k] = false;
    }
    bool canCross(vector<int> &stones)
    {
        for (int i = 0; i < stones.size(); i++)
            mp[stones[i]] = i;

        if (stones[1] != 1)
            return false;

        return solve(1, 1, stones);
    }
};
// @lc code=end
