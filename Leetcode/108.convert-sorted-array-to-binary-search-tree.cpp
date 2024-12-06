/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *solve(int start, int end, vector<int> &nums)
    {
        if (start <= end)
        {
            int mid = start + (end - start) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = solve(start, mid - 1, nums);
            root->right = solve(mid + 1, end, nums);
            return root;
        }
        return NULL;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return solve(0, nums.size() - 1, nums);
    }
};
// @lc code=end
