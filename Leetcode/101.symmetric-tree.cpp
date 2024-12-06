/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool check(TreeNode *left, TreeNode *right)
    {
        if (right == NULL and left == NULL)
            return true;

        if (left == NULL or right == NULL)
            return false;

        if (left->val != right->val)
            return false;

        if (check(left->left, right->right) == false)
            return false;

        if (check(left->right, right->left) == false)
            return false;

        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        return check(root->left, root->right);
    }
};
// @lc code=end
