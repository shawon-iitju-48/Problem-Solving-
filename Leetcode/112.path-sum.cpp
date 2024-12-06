/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool solve(TreeNode *root, int currentSum, int &targetSum)
    {
        if (root == NULL)
            return false;

        int sum = currentSum + root->val;

        if (root->left == NULL and root->right == NULL)
            return targetSum == sum;

        if (solve(root->left, sum, targetSum))
            return true;

        if (solve(root->right, sum, targetSum))
            return true;

        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return solve(root, 0, targetSum);
    }
};
// @lc code=end
