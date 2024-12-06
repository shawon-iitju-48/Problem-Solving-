/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode *root)
    {
        if (root != NULL)
        {

            flatten(root->left);
            flatten(root->right);
            TreeNode *temp = NULL;
            if (root->right != NULL and root->left != NULL)
            {
                temp = root->left;
                while (temp->right != NULL or temp->left != NULL)
                {
                    if (temp->right != NULL)
                        temp = temp->right;
                    else
                        temp = temp->left;
                }
            }
            if (temp != NULL)
                temp->right = root->right;
            if (root->left != NULL)
                root->right = root->left;
            root->left = NULL;
        }
    }
};
// @lc code=end
