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
    TreeNode *construct(int rootvalindex, int start, int end, unordered_map<int, int> &mp, vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[rootvalindex]);
        if (start == end)
            return root;
        int right = end - mp[preorder[rootvalindex]], left = mp[preorder[rootvalindex]] - start;
        if (left > 0)
            root->left = construct(rootvalindex + 1, start, mp[preorder[rootvalindex]] - 1, mp, preorder);
        if (right > 0)
            root->right = construct(rootvalindex + left + 1, mp[preorder[rootvalindex]] + 1, end, mp, preorder);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size() - 1;
        unordered_map<int, int> mp;
        for (int i = 0; i <= n; i++)
            mp[inorder[i]] = i;
        return construct(0, 0, n, mp, preorder);
    }
};