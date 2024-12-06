/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        vector<pair<int, int>> v;
        int level = 1;
        queue<pair<TreeNode *, int>> q;
        TreeNode *temp;

        if (root == NULL)
            return ans;

        q.push(make_pair(root, 1));
        while (!q.empty())
        {
            temp = q.front().first;
            level = q.front().second;
            if (temp->left != NULL)
                q.push(make_pair(temp->left, level + 1));
            if (temp->right != NULL)
                q.push(make_pair(temp->right, level + 1));
            v.push_back(make_pair(temp->val, level));
            q.pop();
        }
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i].second != v[i + 1].second)
                ans.push_back(v[i].first);
        }
        ans.push_back(v[v.size() - 1].first);
        return ans;
    }
};
// @lc code=end
