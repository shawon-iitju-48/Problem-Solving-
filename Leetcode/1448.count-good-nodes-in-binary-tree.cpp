/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int cnt = 0;
    void preorder(TreeNode *root, int &mx)
    {
        if (root != NULL)
        {
            if (root->val >= mx)
                cnt++;
            mx = max(mx, root->val);
            preorder(root->left, mx);
            preorder(root->right, mx);
        }
    }
    int goodNodes(TreeNode *root)
    {
        preorder(root, root->val);
        return cnt;
    }
};
// @lc code=end
