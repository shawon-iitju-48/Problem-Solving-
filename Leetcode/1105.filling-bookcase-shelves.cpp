/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution
{
public:
    int width;
    int solve(int idx, vector<vector<int>> &books, vector<int> &dp)
    {
        if (idx == books.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int mn = INT_MAX, mx = INT_MIN, sum = 0;
        for (int i = idx; i < books.size(); i++)
        {
            sum += books[i][0];
            if (sum > width)
                break;
            mx = max(mx, books[i][1]);
            mn = min(mn, mx + solve(i + 1, books, dp));
        }
        return dp[idx] = mn;
    }
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        width = shelfWidth;
        vector<int> dp(books.size(), -1);
        int res = solve(0, books, dp);
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
