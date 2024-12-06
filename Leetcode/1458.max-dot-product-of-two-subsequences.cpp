/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
class Solution
{
public:
    int dp[501][501];
    const int inf = -1e9;
    int solve(int fi, int si, vector<int> &nums1, vector<int> &nums2)
    {
        if (fi >= nums1.size() || si >= nums2.size())
            return INT_MIN;

        if (dp[fi][si] != inf)
            return dp[fi][si];

        int x = solve(fi + 1, si + 1, nums1, nums2), prod = nums1[fi] * nums2[si];

        int mx = (x == INT_MIN) ? prod : prod + x;

        mx = max(mx, prod);
        mx = max(mx, solve(fi + 1, si, nums1, nums2));
        mx = max(mx, solve(fi, si + 1, nums1, nums2));

        return dp[fi][si] = mx;
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i < 501; i++)
            for (int j = 0; j < 501; j++)
                dp[i][j] = inf;
        return solve(0, 0, nums1, nums2);
    }
};
// @lc code=end
