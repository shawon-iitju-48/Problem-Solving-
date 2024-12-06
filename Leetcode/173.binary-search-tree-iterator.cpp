/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator
{
public:
    stack<TreeNode *> stk;
    BSTIterator(TreeNode *root)
    {
        while (root != NULL)
        {
            stk.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *temp = stk.top();
        stk.pop();
        int res = temp->val;
        temp = temp->right;
        while (temp != NULL)
        {
            stk.push(temp);
            temp = temp->left;
        }
        return res;
    }

    bool hasNext()
    {
        if (stk.empty())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
