/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution
{
public:
    int dp[501][501];
    int solve(int fi, int si, vector<int> &nums1, vector<int> &nums2)
    {
        if (fi >= nums1.size() or si >= nums2.size())
            return 0;

        if (dp[fi][si] != -1)
            return dp[fi][si];

        int mx = solve(fi + 1, si, nums1, nums2);

        if (nums1[fi] == nums2[si])
            mx = max(mx, 1 + solve(fi + 1, si + 1, nums1, nums2));
        else
            mx = max(mx, solve(fi, si + 1, nums1, nums2));

        return dp[fi][si] = mx;
    }
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums1, nums2);
    }
};
// @lc code=end
