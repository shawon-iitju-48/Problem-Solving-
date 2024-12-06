/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int balance(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftmax = balance(root->left);
        if (leftmax == -1)
            return -1;
        int rightmax = balance(root->right);
        if (rightmax == -1)
            return -1;

        if (abs(leftmax - rightmax) > 1)
            return -1;

        return max(leftmax, rightmax) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (balance(root) == -1)
            return false;
        else
            return true;
    }
};
// @lc code=end
