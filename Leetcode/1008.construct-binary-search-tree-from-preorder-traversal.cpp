/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode *solve(int &index, int ub, vector<int> &preorder)
    {
        if (index == preorder.size())
            return NULL;
        if (preorder[index] < ub)
        {
            TreeNode *root = new TreeNode(preorder[index]);
            index++;
            root->left = solve(index, root->val, preorder);
            root->right = solve(index, ub, preorder);
            return root;
        }
        return NULL;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int index = 0;
        return solve(index, INT_MAX, preorder);
    }
};
// @lc code=end
