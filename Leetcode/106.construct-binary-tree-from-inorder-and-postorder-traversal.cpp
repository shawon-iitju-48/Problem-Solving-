/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode *construct(int rootvalindex, int start, int end, unordered_map<int, int> &mp, vector<int> &postorder)
    {
        TreeNode *root = new TreeNode(postorder[rootvalindex]);
        if (start == end)
            return root;
        int right = end - mp[postorder[rootvalindex]], left = mp[postorder[rootvalindex]] - start;
        if (left > 0)
            root->left = construct(rootvalindex - right - 1, start, mp[postorder[rootvalindex]] - 1, mp, postorder);
        if (right > 0)
            root->right = construct(rootvalindex - 1, mp[postorder[rootvalindex]] + 1, end, mp, postorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size() - 1;
        unordered_map<int, int> mp;
        for (int i = 0; i <= n; i++)
            mp[inorder[i]] = i;
        return construct(n, 0, n, mp, postorder);
    }
};
// @lc code=end
