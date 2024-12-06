/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    bool findTarget(TreeNode *root, int k)
    {
        stack<TreeNode *> stk, stk2;
        TreeNode *temp = root;
        while (temp != NULL)
        {
            stk.push(temp);
            temp = temp->left;
        }
        temp = root;
        while (temp != NULL)
        {
            stk2.push(temp);
            temp = temp->right;
        }
        while (stk.top() != stk2.top())
        {
            if (stk.top()->val + stk2.top()->val == k)
                return true;
            else if (stk.top()->val + stk2.top()->val < k)
            {
                temp = stk.top()->right;
                stk.pop();
                while (temp != NULL)
                {
                    stk.push(temp);
                    temp = temp->left;
                }
            }
            else
            {
                temp = stk2.top()->left;
                stk2.pop();
                while (temp != NULL)
                {
                    stk2.push(temp);
                    temp = temp->right;
                }
            }
        }
        return false;
    }
};
// @lc code=end
