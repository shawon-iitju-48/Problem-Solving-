/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int depth(TreeNode *root, int &d)
    {
        if (root == NULL)
            return 0;

        int leftmax = depth(root->left, d);
        int rightmax = depth(root->right, d);

        d = max(leftmax, rightmax);
        return d + 1;
    }
    int maxDepth(TreeNode *root)
    {
        int d = 0;
        return depth(root, d);
        ;
    }
};
// @lc code=end
