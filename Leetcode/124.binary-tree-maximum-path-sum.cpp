/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int mx = INT_MIN;
    int maxsum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;

        int left = maxsum(root->left, sum);
        int right = maxsum(root->right, sum);
        sum = max(left + root->val, root->val);
        sum = max(sum, right + root->val);
        mx = max(mx, right + left + root->val);
        mx = max(sum, mx);
        return sum;
    }
    int maxPathSum(TreeNode *root)
    {
        int sum = 0;
        maxsum(root, sum);
        return mx;
    }
};
// @lc code=end
