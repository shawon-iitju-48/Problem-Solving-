/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode *root)
    {
        TreeNode *temp;
        vector<pair<pair<TreeNode *, int>, int>> q;
        int level = 0, mx = 1, cnt = 0, i = 0;
        q.push_back(make_pair(make_pair(root, level), cnt));
        while (i<q.size())
        {
            temp = q[i].first.first;
            level = q[i].first.second;
            cnt=q[i].second;
            if (temp->left != NULL)
                q.push_back(make_pair(make_pair(temp->left, level+1), 2*cnt+1));
            if (temp->right != NULL)
                q.push_back(make_pair(make_pair(temp->right, level+1), 2*cnt+2));
            i++;
        }
        int curr=q.size()-1;
         for(int i=curr;i>0;i--)
        {
            if(q[curr].first.second!=q[i-1].first.second)
            {
                mx=max(mx,q[curr].second-q[i].second+1);
                curr=i-1;
            }
        }
        return mx;
    }
};

// @lc code=end
