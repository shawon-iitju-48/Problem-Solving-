/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<vector<TreeNode *>> thikana;
        TreeNode *temp;
        if (root != NULL)
        {
            thikana.push_back({root});
            ans.push_back({root->val});

            while (true)
            {
                int last = thikana.size() - 1;
                vector<TreeNode *> vthikana;
                vector<int> v;
                for (int i = 0; i < thikana[last].size(); i++)
                {
                    temp = thikana[last][i];
                    if (temp->left != NULL)
                    {
                        vthikana.push_back(temp->left);
                        v.push_back(temp->left->val);
                    }
                    if (temp->right != NULL)
                    {
                        vthikana.push_back(temp->right);
                        v.push_back(temp->right->val);
                    }
                }
                if (v.size() == 0)
                    break;
                else
                {
                    ans.push_back(v);
                    thikana.push_back(vthikana);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
