/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int cnt;
    int inorder(TreeNode *root, int &x)
    {
        if (root == NULL)
            return 0;

        int left = inorder(root->left, x);
        if (left != 0)
            return left;

        x++;
        if (x == cnt)
            return root->val;

        int right = inorder(root->right, x);
        if (right != 0)
            return right;

        return 0;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        cnt = k;
        int x = 0;
        return inorder(root, x);
    }
};
// @lc code=end
