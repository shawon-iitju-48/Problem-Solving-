/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    int check(TreeNode *p, TreeNode *q)
    {
        if ((p == NULL and q != NULL) or (p != NULL and q == NULL))
            return -1;
        if (p == NULL and q == NULL)
            return 0;

        if (p->val != q->val)
            return -1;

        int left = check(p->left, q->left);
        if (left == -1)
            return -1;

        int right = check(p->right, q->right);
        if (right == -1)
            return -1;
        return 0;
    }
    int subcheck(TreeNode *p, TreeNode *q)
    {
        if (p == NULL)
            return -1;
        if (check(p, q) == 0)
            return 0;
        int left = subcheck(p->left, q);
        if (left == 0)
            return 0;
        int right = subcheck(p->right, q);
        if (right == 0)
            return 0;
        return -1;
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (subcheck(root, subRoot) == -1)
            return false;
        else
            return true;
    }
};
// @lc code=end
