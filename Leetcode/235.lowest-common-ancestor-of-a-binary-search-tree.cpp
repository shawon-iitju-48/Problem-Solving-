/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        unordered_map<TreeNode *, int> mp;
        vector<TreeNode *> v;
        TreeNode *temp = root;
        while (temp != NULL)
        {
            mp[temp]++;
            if (temp->val == p->val)
                break;
            else if (temp->val < p->val)
                temp = temp->right;
            else
                temp = temp->left;
        }
        temp = root;
        while (temp != NULL)
        {
            v.push_back(temp);
            if (temp->val == q->val)
                break;
            else if (temp->val < q->val)
                temp = temp->right;
            else
                temp = temp->left;
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (mp.find(v[i]) != mp.end())
                return v[i];
        }
        return root;
    }
};
// @lc code=end
