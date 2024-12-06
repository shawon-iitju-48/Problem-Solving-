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
    bool solve(TreeNode *root, long long lb, long long ub)
    {
        if (root == NULL)
            return true;

        if (root->val >= ub or root->val <= lb)
            return false;

        if (solve(root->left, lb, root->val) == false)
            return false;

        if (solve(root->right, root->val, ub) == false)
            return false;

        return true;
    }
    bool isValidBST(TreeNode *root)
    {
        long long lb = -2147483650, ub = 2147483650;
        return solve(root, lb, ub);
    }
};