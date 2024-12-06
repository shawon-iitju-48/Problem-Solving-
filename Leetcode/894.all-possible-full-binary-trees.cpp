/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> solve(int n, unordered_map<int, vector<TreeNode *>> &dp)
    {
        if (n == 1)
        {
            TreeNode *node = new TreeNode();
            return {node};
        }
        if (dp.count(n))
            return dp[n];

        vector<TreeNode *> ans;
        for (int i = 2; i <= n; i += 2)
        {
            vector<TreeNode *> left = solve(i - 1, dp);
            vector<TreeNode *> right = solve(n - i, dp);
            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode();
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return {};
        unordered_map<int, vector<TreeNode *>> dp;
        return solve(n, dp);
    }
};
// @lc code=end
