/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode *> solve(int start, int end)
    {
        if (start == end)
        {
            TreeNode *node = new TreeNode(start);
            return {node};
        }
        vector<TreeNode *> ans;
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left, right;
            if (start <= i - 1)
                left = solve(start, i - 1);
            if (i + 1 <= end)
                right = solve(i + 1, end);

            if (left.empty() or right.empty())
            {
                for (int j = 0; j < left.size(); j++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    ans.push_back(root);
                }
                for (int j = 0; j < right.size(); j++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->right = right[j];
                    ans.push_back(root);
                }
            }
            else
            {
                for (int j = 0; j < left.size(); j++)
                {
                    for (int k = 0; k < right.size(); k++)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        ans.push_back(root);
                    }
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }
};
// @lc code=end