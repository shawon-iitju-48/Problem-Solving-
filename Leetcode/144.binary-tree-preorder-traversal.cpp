/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *temp = root;
        stack<TreeNode *> stk;
        while (temp != NULL)
        {
            ans.push_back(temp->val);
            stk.push(temp);
            temp = temp->left;
        }
        while (!stk.empty())
        {
            temp = stk.top()->right;
            stk.pop();
            while (temp != NULL)
            {
                ans.push_back(temp->val);
                stk.push(temp);
                temp = temp->left;
            }
        }
        return ans;
    }
};
// @lc code=end
