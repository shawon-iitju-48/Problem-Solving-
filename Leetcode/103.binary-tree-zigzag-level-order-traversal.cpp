/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        deque<TreeNode *> q;
        q.push_front(root);
        ans.push_back({root->val});

        int cnt = 1, i, level = 0;
        while (cnt > 0)
        {
            i = 0;
            level++;
            vector<int> v;
            while (cnt--)
            {
                if (level % 2 == 0)
                {
                    if (q.back()->left != NULL)
                    {
                        q.push_front(q.back()->left);
                        v.push_back(q.back()->left->val);
                        i++;
                    }
                    if (q.back()->right != NULL)
                    {
                        q.push_front(q.back()->right);
                        v.push_back(q.back()->right->val);
                        i++;
                    }
                    q.pop_back();
                }
                else
                {
                    if (q.front()->right != NULL)
                    {
                        q.push_back(q.front()->right);
                        v.push_back(q.front()->right->val);
                        i++;
                    }
                    if (q.front()->left != NULL)
                    {
                        q.push_back(q.front()->left);
                        v.push_back(q.front()->left->val);
                        i++;
                    }
                    q.pop_front();
                }
            }
            cnt = i;
            if (v.size() > 0)
                ans.push_back(v);
        }
        return ans;
    }
};
// @lc code=end
